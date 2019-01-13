#ifndef DEFINE_H
#define DEFINE_H

enum attribute
{
    ATTR_NULL,
    ATTR_OPEN,
    ATTR_CLOSE,
    ATTR_FORBID,
    //打印地图用到 最短路径的每个节点的属性是它
    ATTR_RIGHT
};

#define MAP_ROW      9
#define MAP_COLUMN   9

#define STEP_LENGTH  10


#endif
