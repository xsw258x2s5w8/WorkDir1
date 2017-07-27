#include "videosettings.h"

VideoSettings::VideoSettings()
{

}

int VideoSettings::getVideoFormatId()
{
    return videoFormatId;
}

void VideoSettings::setVideoFormatId(int videoFormatId)
{
    this->videoFormatId = videoFormatId;
}

QString VideoSettings::getVideoFormat()
{
    return videoFormat;
}

void VideoSettings::setVideoFormat(QString videoFormat)
{
    this->videoFormat = videoFormat;
}

QString VideoSettings::getSpecification()
{
    return specification;
}

void VideoSettings::setSpecification(QString specification)
{
    this->specification = specification;
}
