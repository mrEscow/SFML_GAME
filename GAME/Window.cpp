#include "Window.h"

Window::Window()
{

}

Window* Window::wnd = nullptr;
sf::RenderWindow* Window::window = nullptr;

/**
 * Статические методы должны быть определены вне класса.
 */
Window *Window::Get()
{
    /**
     * Это более безопасный способ создания экземпляра.
     * экземпляр = new Singleton опасен, если два потока экземпляра хотят
     * получить доступ одновременно
     */
    if(wnd == nullptr){
        wnd = new Window();
    }

    return wnd;
}

sf::RenderWindow *Window::value() const{

    if(window == nullptr){
        window = new sf::RenderWindow(sf::VideoMode(1920,1080), "");
        window->setVerticalSyncEnabled(true);
    }

    return window;
}

