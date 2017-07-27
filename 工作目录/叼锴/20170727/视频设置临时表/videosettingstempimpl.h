#ifndef VIDEOSETTINGSTEMPIMPL_H
#define VIDEOSETTINGSTEMPIMPL_H
#include <QtSql>
#include "videosettingstemp.h"
class VideoSettingsTempImpl
{
public:
    VideoSettingsTempImpl();
    int deleteSettingTemp();//删除临时表
    int insertVideoSettings(VideoSettingsTemp videoSettings);//把视频设置数据插入到临时表
    VideoSettingsTemp selectVideoSettings();//对临时表进行查询

private:
    QSqlDatabase database;
};

#endif // VIDEOSETTINGSTEMPIMPL_H
