
#pragma once

enum JOB
{
    JOB_NONE,
    JOB_KNIGHT,
    JOB_ARCHER,
    JOB_MAGICIAN,
    JOB_END
};

// Object Type
enum OBJECT_TYPE
{
	OT_PLAYER,
	OT_MONSTER,
	OT_ITEM_WEAPON,
	OT_ITEM_ARMOR
};

// Item Type
enum ITEM_TYPE
{
	IT_WEAPON,
	IT_ARMOR,
	IT_MAX
};

enum STAGE_TYPE
{
	ST_NONE,
	ST_EASY,
	ST_NORMAL,
	ST_HARD,
	ST_BACK
};
