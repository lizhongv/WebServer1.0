#include "webserver.h"

int Handle_Request_Message(char* message, int Socket)
{
    //����HTTP��������Ϣ
    int rval = 0;
    char Method[BUF_SIZE];
    char URI[BUF_SIZE];
    char Version[BUF_SIZE];

    if (sscanf(message, "%s %s %s", Method, URI, Version) != 3)
    {
        printf("Request line error!\n");
        return ERROR;
    }	//��ȡ"���󷽷�"��"URL"��"HTTP�汾"�����ؼ�Ҫ��

    if (Judge_Method(Method, Socket) == ERROR)
    {
        return ERROR;
    }
    else if(Judge_Method(Method, Socket) == "POST")
    {
        Post_Value(message);
    }	//�жϴ���"���󷽷�"

    if (Judge_URI(URI, Socket) == ERROR)
    {
        return ERROR;
    }	//�жϴ���"URI"
    else
        rval = Send_File(URI, Socket);

    if (rval == OK)
    {
        printf("The process is successfully finished!\n");
    }

    return OK;
}
