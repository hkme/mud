#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", NOR + HIB "\n\n                ��        ��        ��" NOR);
        set("long", HIB "\n"
"�������𣬻�����Χ��������ϸ���룬�ڴ���棬������ɽ��\n"
"������ǰ���������ƶ�ҵ��ͬ���ڶ��������ܵĹ���Ҳ�᲻ͬ��\n"
"�������Ǽ�������ʳ����ȴ�Ĵ�������ʳ���ܣ�������ˮȴ��\n"
"���ŧѪ���������ã�������ˮ�ɻ���Ǻ�ϸ�޷���ʳ��\n\n" NOR);
        setup();
}
