inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
ÿһ�䷿�д󶼹��з���żȻ�ڱ��ϼ����������ģ�д
���Ǹ߲�����������̩���������ʮ����ȵ���������һ����
���й��Ķ��Ǻ�����������д�Ŵ����ʥ��ʦ����λ������
������ʮ�ˣ�д���ջء���·���ӹ������ġ����ŵ����֡�
LONG);
        set("exits", ([
                "south" : __DIR__"wroom2",
                "northwest" : __DIR__"zoulangw",
        ]));
        set("maze", 1);
        setup();
        replace_program(ROOM);
}