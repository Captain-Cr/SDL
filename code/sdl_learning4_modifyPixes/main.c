#include <stdio.h>
#include <SDL2/SDL.h>

/*
	Describe: 修改像素
*/

#define WIDTH 400
#define HIGHT 300

void sdl_event_loop()
{
	// 循环检测事件，并打印输出事件的类型
    while(1)
    {
            SDL_Event  event;
            if(SDL_PollEvent(&event))
            {
                printf("event type, %d\n", event.type);
                if(event.type == SDL_QUIT)
                {
                    break;
                }
            }

    }
}

int main()
{
    // 初始化窗口，成功返回0
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Can not init video, %s", SDL_GetError());
        return 1;
    }

    // 创建一个窗口指针
    SDL_Window *win = SDL_CreateWindow(
                                                        "Hello world",
                                                        SDL_WINDOWPOS_CENTERED,
                                                        SDL_WINDOWPOS_CENTERED,   
							WIDTH,  HIGHT,
                                                        SDL_WINDOW_SHOWN);

    if(win == NULL)
    {
        SDL_Log("Can not create window, %s",SDL_GetError());
        return 1;
    }

    

    SDL_Surface *screen = SDL_GetWindowSurface(win);	// screen是指向创建窗口的指针
    SDL_Rect r = {0, 0, WIDTH/2, HIGHT/2};		// 矩形结构体
    SDL_FillRect(screen, &r, 0xff00ff00);			// 4个字节，32位，ARGB
    

    // 修改像素,  (知道了高、宽以及每一个像素是4个字节,  screen->pixels是一个无符号指针)
    for(int i = HIGHT / 2; i < HIGHT; i++)
    {
	for(int j = WIDTH / 2; j < WIDTH; j++)
	{
	    ((uint32_t *)(screen->pixels))[i*WIDTH + j] = 0xffff0000;
	}
    }
    
    SDL_UpdateWindowSurface(win);			// 更新窗口，渲染
    sdl_event_loop();             // 打印事件类型



    SDL_Delay(300);
    SDL_DestroyWindow(win);

    return 0;
}
