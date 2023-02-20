/*
	Description:使用SDL进行图形绘制和文字绘制
	
	Copyright:2023-2-19 
*/

#include <iostream>
extern "C"
{	
    #include <SDL2/SDL.h>
}

#define WIDTH 600		// 宽
#define HIGHT 500		// 高
#define FRAMERATE 30	// 帧率

typedef void (*CallFunction)(SDL_Window *win, SDL_Renderer *renderer);		// 定义回调函数原型，函数指针名称为CallFunction,该函数传入两个参数，返回类型为void
using namespace std;


void callbackfunction(SDL_Window *win, SDL_Renderer *renderer)
{
	// 回调函数， 可根据不同任务编写不同代码
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	
	//显示图像
	SDL_RenderPresent(renderer);
	
}


void sdl_event_loop(SDL_Window *win, SDL_Renderer *renderer,CallFunction callback)
{
	// 循环事件, 可以在里面负责渲染等工作
	// Args:
	// 		CallFunction callback是回调函数，负责渲染等工作
	
	while(1)								// 不断检测事件
	{
		
		uint32_t begin = SDL_GetTicks();	// 获取开始时间
		SDL_Event event;
		if(SDL_PollEvent(&event))		
		{
			if(event.type == SDL_QUIT)		// 退出循环
			{
				return;
			}
		}
		
		callback(win, renderer);		// 执行回调函数
		
		//设定固定帧率
		uint32_t current = SDL_GetTicks();	// 获取当前时间
		uint32_t cost = current - begin;	// 当前程序运行的总花费时间
		uint32_t TimeByOneFrame = 1000 / FRAMERATE;		// 一帧需要的时间，ms
		long delay = TimeByOneFrame - cost;				// 需要延时的时长，如果程序花费时间大于一帧的时间，那么就不延时;否则延时的时长为delay
		if(delay > 0)
		{
			SDL_Delay(delay);	
		}
	}
}




int main(int argc, char* argv[])
{
	// 初始化sdl
	if(SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Can not init video, %s", SDL_GetError());
		return 1;
	}
	
	// 创建窗口指针
	SDL_Window *win = SDL_CreateWindow(
											"Renderer Graphics",
											SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											WIDTH, HIGHT,
											SDL_WINDOW_SHOWN);
	if(win == NULL)
	{
		SDL_Log("Can not create window, %s",SDL_GetError());
		return 1;
	}
	
	
	// 创建着色器指针
	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		SDL_Log("Can not create Renderer, %s",SDL_GetError());
	}
	
	// 循环事件， 负责渲染
	sdl_event_loop(win, renderer, callbackfunction);
	
	
	
	
	// 销毁指针
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	
	return 0;
	
	
	
	
}
