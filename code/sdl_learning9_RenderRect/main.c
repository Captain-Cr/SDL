#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


/*
	Describe: 使用着色器(Render)绘制一个矩形

	（1）创建Renderer结构体，所有渲染操作都是在基础之上完成的。
	函数：
		SDL_Renderer* SDL_CreateRenderer(SDL_Window* win, int index, uint32 flags);
	参数说明：第一个参数用来指定渲染的目标窗口；
		  第二个参数是指定渲染设备的索引标识，可设置为-1，让SDL自动选择当前操作系统最适合的渲染设备。
		 第三个参数是代表一些常用的渲染标记位，如果设置为SDL_RENDERER_ACCELERATED（0）代表创建渲染器优先支持硬件加速的渲染设备。

	如果函数成功，则会返回有效的SDL_Renderer指针

	（2）创建成功在退出之前要进行销毁，销毁函数：
		SDL_DestroyRenderer(*Renderer);

	（3）渲染过程：清除背景-->渲染图像-->显示图像
	通过SDL_SetRenderDrawColor()设置默认的渲染颜色
	通过SDL_RenderPresent()呈现结果。
	

	
*/

#define WIDTH 600
#define HIGHT 500
#define FRAMERATE 30	// 帧频率，30fps


int x = 0;
SDL_Window *win;	        // SDL窗口
SDL_Renderer *renderer;		// 创建一个着色器，用于渲染


void draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);     // 设置着色器绘制的颜色
	SDL_RenderClear(renderer);	// 清除
	
	SDL_Rect r= {0, 0, 100, 100};	
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);	//混合显示a通道
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &r);	// 绘制矩形

	SDL_Rect r1= {50, 50, 100, 100};	
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &r1);	// 绘制矩形

	SDL_RenderPresent(renderer);
    
}



void sdl_event_loop()
{
	// 循环检测事件，并打印输出事件的类型
    while(1)
    {
	    uint32_t begin = SDL_GetTicks();	// 获取开始时间

            SDL_Event  event;
	        draw();		// 绘制
            while(SDL_PollEvent(&event))
            {
                printf("event type, %d\n", event.type);
                if(event.type == SDL_QUIT)
                {
                    return;
                }
            }
	    
	    // 设定固定帧率
	    uint32_t current = SDL_GetTicks();	   // 获取当前时间
	    uint32_t cost = current - begin;	   // 获取程序运行的时间
	    uint32_t TimeByOneFrame = 1000 / FRAMERATE;	// 一帧所需要的时间,ms
	    long delay = TimeByOneFrame - cost;
	    
	    if(delay > 0)
	    {
	    	SDL_Delay(delay);	// 20ms，50fps
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

    

    /*
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
    */

    
    
    // 创建着色器renderer
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
	SDL_Log("Can not create render, %s", SDL_GetError());
    }

    sdl_event_loop();             // 循环事件



    SDL_Delay(300);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    return 0;
}
