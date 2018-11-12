/**
  ******************************************************************************
  * @file test_server.c
  * @author  leon.xie
  * @version v1.0.0
  * @date 2018-11-6 22:24:11
  * @brief  This file provides all the test_server functions. 
  ******************************************************************************
  * @attention
  *
  * File For Yunin Software Team Only
  *
  * Copyright (C), 2017-2027, Yunin Software Team
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "glib.h"
#include "gio/gio.h"

#include "diagnosis.h"
#include "init.h"
#include "log.h"
#include "kernel.h"
#include "net.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static gboolean
__test_server_handler (GThreadedSocketService *service,
         GSocketConnection      *connection,
         GSocketListener        *listener,
         gpointer                user_data)
{
    GOutputStream *out;
    GInputStream *in;
    gssize size;
	int cnt = 0;
    char buffer[1024] = {0};
    
    out = g_io_stream_get_output_stream (G_IO_STREAM (connection));
    in = g_io_stream_get_input_stream (G_IO_STREAM (connection));

    while (0 < (size = g_input_stream_read (in, buffer,
                                            sizeof(buffer), NULL, NULL)))
	{
		MESSAGE("recv msg from client(%p) : %s",connection,buffer);
        g_output_stream_write (out, buffer, size, NULL, NULL);
        cnt++;
        if(cnt > 10)
        {
        	//关闭连接
        	WARN("server: close connection(%p)",connection);
        	g_io_stream_close(G_IO_STREAM (connection),NULL,NULL);
        }
	}                                            

    return FALSE;
}


int main(int argc, char *argv[])
{
	server_create(DEFAULT_SERVER_PORT,10,__test_server_handler,NULL);
	main_loop_start();
	g_assert_not_reached ();
	return 0;
}


#ifdef  __cplusplus
}
#endif


