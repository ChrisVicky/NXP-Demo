/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#include "../custom/custom.h"

void events_init(lv_ui *ui)
{
}

static void screen_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_demo_music_play(2);
	}
		break;
	default:
		break;
	}
}

static void screen_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_demo_music_play(1);
	}
		break;
	default:
		break;
	}
}

static void screen_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_demo_music_play(0);
	}
		break;
	default:
		break;
	}
}

static void screen_imgbtn_play_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
				if (lv_obj_has_state(guider_ui.screen_imgbtn_play, LV_STATE_CHECKED))
				{
					lv_demo_music_resume();
				} else {
					lv_demo_music_pause();
				}
	}
		break;
	default:
		break;
	}
}

static void screen_img_icn_left_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_demo_music_album_next(false);
	}
		break;
	default:
		break;
	}
}

static void screen_img_icn_right_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_demo_music_album_next(true);
	}
		break;
	default:
		break;
	}
}

static void screen_btn_tracks_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
				if (tracks_is_up())
				{
					tracks_down();
				} else {
					tracks_up();
				}
	}
		break;
	default:
		break;
	}
}

void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event(ui->screen_btn_3, screen_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event(ui->screen_btn_2, screen_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event(ui->screen_imgbtn_play, screen_imgbtn_play_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event(ui->screen_img_icn_left, screen_img_icn_left_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event(ui->screen_img_icn_right, screen_img_icn_right_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event(ui->screen_btn_tracks, screen_btn_tracks_event_handler, LV_EVENT_ALL, ui);
}
