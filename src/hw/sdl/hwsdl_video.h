#ifndef INC_1OOM_HWSDL_VIDEO_H
#define INC_1OOM_HWSDL_VIDEO_H

extern void hw_video_shutdown(void);
extern void hw_video_update(void);
extern void hw_video_refresh(int front);
extern int hw_video_resize(int w, int h);
extern int hw_video_toggle_fullscreen(void);

#endif
