#include <SFML/Graphics.hpp>
#include <entt.hpp>

struct VelocityComponent {
    float x = 0.f;
    float y = 0.f;
};

struct SpriteComponent {
    sf::Texture texture;
    sf::Sprite sprite;

    SpriteComponent(const std::string& filename) {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
    }
};

struct TransformComponent {
    sf::Vector2f position;

    TransformComponent(float x, float y) : position(x, y) {}
};

void handleCollisions(entt::registry& registry) {
    auto view = registry.view<TransformComponent, VelocityComponent, SpriteComponent>();

    for (auto entity : view) {
        auto& transform = view.get<TransformComponent>(entity);
        auto& velocity = view.get<VelocityComponent>(entity);
        auto& sprite = view.get<SpriteComponent>(entity);

        sf::FloatRect boundingBox = sprite.sprite.getGlobalBounds();

        for (auto otherEntity : view) {
            if (entity == otherEntity) {
                continue;
            }

            auto& otherTransform = view.get<TransformComponent>(otherEntity);
            auto& otherSprite = view.get<SpriteComponent>(otherEntity);

            sf::FloatRect otherBoundingBox = otherSprite.sprite.getGlobalBounds();

            if (boundingBox.intersects(otherBoundingBox)) {
                // Handle collisions here
            }
        }
    }
}

void updateEntities(entt::registry& registry, float deltaTime) {
    auto view = registry.view<TransformComponent, VelocityComponent>();

    for (auto entity : view) {
        auto& transform = view.get<TransformComponent>(entity);
        auto& velocity = view.get<VelocityComponent>(entity);

        transform.position.x += velocity.x * deltaTime;
        transform.position.y += velocity.y * deltaTime;
    }
}



int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mario");

    entt::registry registry;

    auto playerEntity = registry.create();
    registry.emplace<SpriteComponent>(playerEntity, "D:/AI/Projects/Toxic/1x/chel.png");
    registry.emplace<TransformComponent>(playerEntity, 400.f, 300.f);
    registry.emplace<VelocityComponent>(playerEntity, 0.f, 0.f);

    auto platformEntity = registry.create();
    registry.emplace<SpriteComponent>(platformEntity, "D:/AI/Projects/Toxic/1x/1x/greenTiles.png");
    registry.emplace<TransformComponent>(platformEntity, 400.f, 550.f);
    registry.emplace<VelocityComponent>(platformEntity, 0.f, 0.f);

    // Add more platforms here

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        handleCollisions(registry);
        updateEntities(registry, deltaTime);

        window.clear(sf::Color::Black);

        auto view = registry.view<SpriteComponent, TransformComponent>();
        for (auto entity : view) {
            auto& sprite = view.get<SpriteComponent>(entity);
            auto& transform = view.get<TransformComponent>(entity);

            sprite.sprite.setPosition(transform.position);
            window.draw(sprite.sprite);
        }

        // Display text on the screen
        sf::Font font;
        //font.loadFromFile("arial.ttf");
        sf::Text text("Hello, Mario!", font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        window.draw(text);

        window.display();
    }

    return 0;
}
