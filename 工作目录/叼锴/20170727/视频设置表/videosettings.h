#ifndef VIDEOSETTINGS_H
#define VIDEOSETTINGS_H
#include <QString>
class VideoSettings
{
public:
    VideoSettings();
    int getVideoFormatId();
    void setVideoFormatId(int videoFormatId);
    QString getVideoFormat();
    void setVideoFormat(QString videoFormat);
    QString getSpecification();
    void setSpecification(QString specification);


private:
    int videoFormatId;//视频格式id
    QString videoFormat;//视频格式
    QString specification;//规格
};

#endif // VIDEOSETTINGS_H
