#ifndef WINDOW_H
#define WINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>

class Window
{
public:

    /**
     * Одиночки не должны быть клонируемыми.
     */
    Window(Window &other) = delete;
    /**
     * Одиночки не должны быть присваиваемыми.
     */
    void operator=(const Window &) = delete;
    /**
     * Это статический метод, управляющий доступом к экземпляру одиночки. При
     * первом запуске, он создаёт экземпляр одиночки и помещает его в
     * статическое поле. При последующих запусках, он возвращает клиенту объект,
     * хранящийся в статическом поле.
     */

    static Window *Get();
    /**
     * Наконец, любой одиночка должен содержать некоторую бизнес-логику, которая
     * может быть выполнена на его экземпляре.
     */
    void SomeBusinessLogic()
    {
        // ...
    }

     sf::RenderWindow* value() const;
protected:
    Window();

    static Window* wnd;

private:
    static sf::RenderWindow* window;

};

#endif // WINDOW_H
