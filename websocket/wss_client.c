// #include "../my_ftl/headers/ftl.h"
#include "../includes.h"

t_ship *global_ship;
t_global *global_global;
t_ennemy *global_ennemy;

static int destroy_flag = 0;
static int connection_flag = 0;
static int writeable_flag = 0;

static void INT_HANDLER(int signo) {
  destroy_flag = 0;
}

struct session_data {
  int fd;
};

struct pthread_routine_tool {
  struct libwebsocket_context *context;
  struct libwebsocket *wsi;
};

static int websocket_write_back(struct libwebsocket *wsi_in, char *str, int str_size_in)
{
  if (str == NULL || wsi_in == NULL)
  return -1;

  int n;
  int len;
  char *out = NULL;

  if (str_size_in < 1)
  len = strlen(str);
  else
  len = str_size_in;

  out = (char *)malloc(sizeof(char)*(LWS_SEND_BUFFER_PRE_PADDING + len + LWS_SEND_BUFFER_POST_PADDING));
  //* setup the buffer*/
  memcpy (out + LWS_SEND_BUFFER_PRE_PADDING, str, len );
  //* write out*/
  n = libwebsocket_write(wsi_in, out + LWS_SEND_BUFFER_PRE_PADDING, len, LWS_WRITE_TEXT);
  //* free the buffer*/
  free(out);

  return n;
}



static int ws_service_callback(struct libwebsocket_context *context,
  struct libwebsocket *wsi,
  enum libwebsocket_callback_reasons reason, void *user,
  void *in, size_t len)
  {

    switch (reason) {

      case LWS_CALLBACK_CLIENT_ESTABLISHED:
      // printf(KYEL"[Main Service] Connect with server success.\n"RESET);
      connection_flag = 1;
      break;

      case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
      // printf(KRED"[Main Service] Connect with server error.\n"RESET);
      destroy_flag = 1;
      connection_flag = 0;
      break;

      case LWS_CALLBACK_CLOSED:
      /*                    printf(KYEL"[Main Service] LWS_CALLBACK_CLOSED\n"RESET);
      destroy_flag = 1;
      connection_flag = 0;*/
      break;

      case LWS_CALLBACK_CLIENT_RECEIVE:
      printf(KCYN_L"[Main Service] Client recvived:%s\n"RESET, (char *)in);
      if (my_strcmp((char *)in, "attack") == 0) {
        attack(global_ship, global_ennemy);
      }
      else if (my_strcmp((char *)in, "getbonus") == 0) {
        get_bonus(global_ship, global_ennemy);
      }
      else if (my_strcmp((char *)in, "jump") == 0) {
        jump(global_ship, global_ennemy);
      }
      else if (my_strcmp((char *)in, "system_repair") == 0) {
        ftl_drive_system_repair(global_ship);
        navigation_tools_system_repair(global_ship);
        weapon_system_repair(global_ship);
      }






      if (writeable_flag)
      destroy_flag = 1;

      break;
      case LWS_CALLBACK_CLIENT_WRITEABLE :
      // printf(KYEL"[Main Service] On writeable is called. send byebye message\n"RESET);
      websocket_write_back(wsi, "Byebye! See you later", -1);
      //                      writeable_flag = 1;
      break;

      default:
      break;
    }
    return 0;
  }



  static void *pthread_routine(void *tool_in)
  {
    struct pthread_routine_tool *tool = tool_in;

    // printf(KBRN"[pthread_routine] Good day. This is pthread_routine.\n"RESET);

    //* waiting for connection with server done.*/
    // while(!connection_flag)
    // usleep(1000*20);

    //*Send greeting to server*/
    // printf(KBRN"[pthread_routine] Server is ready. send a greeting message to server.\n"RESET);
    websocket_write_back(tool->wsi, "Good day", -1);

    // printf(KBRN"[pthread_routine] sleep 2 seconds then call onWritable\n"RESET);
    // sleep(1);
    // printf(KBRN"------------------------------------------------------\n"RESET);
    // sleep(1);
    //printf(KBRN"[pthread_routine] sleep 2 seconds then call onWritable\n"RESET);

    //*involked wriable*/
    // printf(KBRN"[pthread_routine] call on writable.\n"RESET);
    libwebsocket_callback_on_writable(tool->context, tool->wsi);

  }

  // int main()
  int launch_websocket(t_global *global, t_ship *ship)
  {
    global_global = global;
    global_ship = ship;
    //* register the signal SIGINT handler */
    struct sigaction act;
    act.sa_handler = INT_HANDLER;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction( SIGINT, &act, 0);


    struct libwebsocket_context *context = NULL;
    struct lws_context_creation_info info;
    struct libwebsocket *wsi = NULL;
    struct libwebsocket_protocols protocol;

    memset(&info, 0, sizeof info);
    info.port = CONTEXT_PORT_NO_LISTEN;
    info.iface = NULL;
    info.protocols = &protocol;
    info.ssl_cert_filepath = NULL;
    info.ssl_private_key_filepath = NULL;
    info.extensions = libwebsocket_get_internal_extensions();
    info.gid = -1;
    info.uid = -1;
    info.options = 0;

    protocol.name  = "my-echo-protocol";
    protocol.callback = &ws_service_callback;
    protocol.per_session_data_size = sizeof(struct session_data);
    protocol.rx_buffer_size = 0;
    //      protocol.id = 0;
    //      protocol.user = NULL;

    context = libwebsocket_create_context(&info);
    // printf(KRED"[Main] context created.\n"RESET);

    if (context == NULL) {
      // printf(KRED"[Main] context is NULL.\n"RESET);
      return -1;
    }


    wsi = libwebsocket_client_connect(context, "localhost", 5000, 0,
    "/", "localhost:5000", NULL,
    protocol.name, -1);
    if (wsi == NULL) {
      // printf(KRED"[Main] wsi create error.\n"RESET);
      return -1;
    }

    // printf(KGRN"[Main] wsi create success.\n"RESET);

    struct pthread_routine_tool tool;
    tool.wsi = wsi;
    tool.context = context;

    pthread_t pid;
    pthread_create(&pid, NULL, pthread_routine, &tool);
    pthread_detach(pid);

    // while(!destroy_flag)
    // {
    //   libwebsocket_service(context, 50);
    // }
    t_ennemy			*ennemy;
    if ((ennemy = malloc(sizeof(t_ennemy))) == NULL)
    return -1;
    global_ennemy = ennemy;
    start_game(global, ship, context, global_ennemy);

    libwebsocket_context_destroy(context);

    return 0;
  }
