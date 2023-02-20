#include <stdio.h>
#include <SDL2/SDL.h>

/*
	Describe: 循环检测事件
*/

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
                                                        SDL_WINDOWPOS_CENTERED,   400,  300,
                                                        SDL_WINDOW_SHOWN);

    if(win == NULL)
    {
        SDL_Log("Can not create window, %s",SDL_GetError());
        return 1;
    }

    // 循环检测时间，并打印输出事件的类型
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

    SDL_Delay(3000);
    SDL_DestroyWindow(win);

    return 0;
}
