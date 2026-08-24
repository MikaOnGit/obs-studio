/******************************************************************************
    Copyright (C) 2023 by Lain Bailey <lain@obsproject.com>
                          Zachary Lund <admin@computerquip.com>
                          Philippe Groarke <philippe.groarke@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "OBSBasic.hpp"

#include <cstring>

QIcon OBSBasic::GetSourceIcon(const char *id) const
{
	return GetIconFromType(obs_source_get_icon_type(id), id);
}

QIcon OBSBasic::GetSourceIcon(obs_source_t *source) const
{
	if (!source) {
		return GetDefaultIcon();
	}

	const char *id = obs_source_get_id(source);

	OBSDataAutoRelease privSettings = obs_source_get_private_settings(source);
	if (obs_data_has_user_value(privSettings, "icon-type-override")) {
		return GetIconFromType((int)obs_data_get_int(privSettings, "icon-type-override"), id);
	}

	if (strcmp(id, "scene") == 0) {
		return GetSceneIcon();
	}
	if (strcmp(id, "group") == 0) {
		return GetGroupIcon();
	}

	return GetSourceIcon(id);
}

QIcon OBSBasic::GetIconFromType(int iconType, const char *id) const
{
	switch (iconType) {
	case OBS_ICON_TYPE_IMAGE:
		return GetImageIcon();
	case OBS_ICON_TYPE_COLOR:
		return GetColorIcon();
	case OBS_ICON_TYPE_SLIDESHOW:
		return GetSlideshowIcon();
	case OBS_ICON_TYPE_AUDIO_INPUT:
		return GetAudioInputIcon();
	case OBS_ICON_TYPE_AUDIO_OUTPUT:
		return GetAudioOutputIcon();
	case OBS_ICON_TYPE_DESKTOP_CAPTURE:
		return GetDesktopCapIcon();
	case OBS_ICON_TYPE_WINDOW_CAPTURE:
		return GetWindowCapIcon();
	case OBS_ICON_TYPE_GAME_CAPTURE:
		return GetGameCapIcon();
	case OBS_ICON_TYPE_CAMERA:
		return GetCameraIcon();
	case OBS_ICON_TYPE_TEXT:
		return GetTextIcon();
	case OBS_ICON_TYPE_MEDIA:
		return GetMediaIcon();
	case OBS_ICON_TYPE_BROWSER:
		return GetBrowserIcon();
	case OBS_ICON_TYPE_CUSTOM:
		return id ? GetCustomIcon(id) : GetDefaultIcon();
	case OBS_ICON_TYPE_PROCESS_AUDIO_OUTPUT:
		return GetAudioProcessOutputIcon();
	case ICON_TYPE_SCENE:
		return GetSceneIcon();
	case ICON_TYPE_GROUP:
		return GetGroupIcon();
	default:
		return GetDefaultIcon();
	}
}

void OBSBasic::SetImageIcon(const QIcon &icon)
{
	imageIcon = icon;
}

void OBSBasic::SetColorIcon(const QIcon &icon)
{
	colorIcon = icon;
}

void OBSBasic::SetSlideshowIcon(const QIcon &icon)
{
	slideshowIcon = icon;
}

void OBSBasic::SetAudioInputIcon(const QIcon &icon)
{
	audioInputIcon = icon;
}

void OBSBasic::SetAudioOutputIcon(const QIcon &icon)
{
	audioOutputIcon = icon;
}

void OBSBasic::SetDesktopCapIcon(const QIcon &icon)
{
	desktopCapIcon = icon;
}

void OBSBasic::SetWindowCapIcon(const QIcon &icon)
{
	windowCapIcon = icon;
}

void OBSBasic::SetGameCapIcon(const QIcon &icon)
{
	gameCapIcon = icon;
}

void OBSBasic::SetCameraIcon(const QIcon &icon)
{
	cameraIcon = icon;
}

void OBSBasic::SetTextIcon(const QIcon &icon)
{
	textIcon = icon;
}

void OBSBasic::SetMediaIcon(const QIcon &icon)
{
	mediaIcon = icon;
}

void OBSBasic::SetBrowserIcon(const QIcon &icon)
{
	browserIcon = icon;
}

void OBSBasic::SetGroupIcon(const QIcon &icon)
{
	groupIcon = icon;
}

void OBSBasic::SetSceneIcon(const QIcon &icon)
{
	sceneIcon = icon;
}

void OBSBasic::SetDefaultIcon(const QIcon &icon)
{
	defaultIcon = icon;
}

void OBSBasic::SetAudioProcessOutputIcon(const QIcon &icon)
{
	audioProcessOutputIcon = icon;
}

QIcon OBSBasic::GetImageIcon() const
{
	return imageIcon;
}

QIcon OBSBasic::GetColorIcon() const
{
	return colorIcon;
}

QIcon OBSBasic::GetSlideshowIcon() const
{
	return slideshowIcon;
}

QIcon OBSBasic::GetAudioInputIcon() const
{
	return audioInputIcon;
}

QIcon OBSBasic::GetAudioOutputIcon() const
{
	return audioOutputIcon;
}

QIcon OBSBasic::GetDesktopCapIcon() const
{
	return desktopCapIcon;
}

QIcon OBSBasic::GetWindowCapIcon() const
{
	return windowCapIcon;
}

QIcon OBSBasic::GetGameCapIcon() const
{
	return gameCapIcon;
}

QIcon OBSBasic::GetCameraIcon() const
{
	return cameraIcon;
}

QIcon OBSBasic::GetTextIcon() const
{
	return textIcon;
}

QIcon OBSBasic::GetMediaIcon() const
{
	return mediaIcon;
}

QIcon OBSBasic::GetBrowserIcon() const
{
	return browserIcon;
}

QIcon OBSBasic::GetGroupIcon() const
{
	return groupIcon;
}

QIcon OBSBasic::GetSceneIcon() const
{
	return sceneIcon;
}

QIcon OBSBasic::GetDefaultIcon() const
{
	return defaultIcon;
}

QIcon OBSBasic::GetAudioProcessOutputIcon() const
{
	return audioProcessOutputIcon;
}

QIcon OBSBasic::GetCustomIcon(const char *id) const
{
	const char *path = App()->IsThemeDark() ? obs_source_get_dark_icon(id) : obs_source_get_light_icon(id);
	QIcon icon = (path && *path) ? QIcon(path) : GetDefaultIcon();
	bfree((void *)path);

	return icon;
}
