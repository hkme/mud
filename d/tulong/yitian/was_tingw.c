#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������µĲ��������ϰ��ż������š�
LONG );
        set("exits", ([
                "east" : "/d/tulong/yitian/was_zoulang1",
        ]));

        set("outdoors", "beijing");
        setup();
}

