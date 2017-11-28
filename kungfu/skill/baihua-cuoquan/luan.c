#include <ansi.h>
#include <combat.h>

#define LUAN "��" HIW "�ٻ�����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, ap, dp, damage;
	string msg;

        if (userp(me) && ! me->query("can_perform/baihua-cuoquan/luan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        skill = me->query_skill("baihua-cuoquan", 1);

        if (skill < 120)
                return notify_fail("��İٻ���ȭ�ȼ�����������ʩչ" LUAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" LUAN "��\n");
 
        if (me->query_skill_mapped("unarmed") != "baihua-cuoquan")
                return notify_fail("��û�м����ٻ���ȭ������ʩչ" LUAN "��\n");

        if (me->query_skill_prepared("unarmed") != "baihua-cuoquan")
                return notify_fail("������û��׼��ʹ�ðٻ���ȭ���޷�ʹ��" LUAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "�ٲ�������˫�Ƴ�$n" HIW "����������Ʒ�ȭӰ��"
              "�ص���������һ�С��ٻ����ҡ���\n" NOR;
	me->add("neili", -50);

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -150);
                damage = ap / 8 + random(ap / 8);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 0,
                                           HIR "$n" HIR "ֻ��$N" HIR "ȭӰ���أ�"
                                           "��ʱ�ۻ����ң�������ȭ�������˸�����"
                                           "������\n" NOR);
                me->start_busy(1);
                if (ap / 2 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 30 + 2);
        } else
        {
                msg += CYN "$n" CYN "ֻ��$N" CYN "ȭ����ӿ���������ӣ���æ�����"
                       "�����������⿪����\n" NOR;
                me->add("neili", -80);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
