#include "Room.h"
#include "Item.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"

int main() {
    std::string playerName;
    std::cout << "¡Bienvenido a la aventura de Fortnite!\n";
    std::cout << "Por favor, ingresa tu nombre: ";


    std::cin >> playerName;

    int initialHealth = 100;
    int initialLives = 3;

    Player player(playerName, 100, 3);

    Game adventure;

    Room* currentRoom = adventure.createRoom("Haunted Hills", "El comienzo de tu aventura, Un lugar lleno de casas abandonadas y tesoros.");
    currentRoom->addItem(Item("Llave", "Abre una puerta de un sotano con una Grieta", Item::ItemType::KEY));

    currentRoom = adventure.createRoom("Mega City", "Una torre alta con vistas espectaculares.");
    currentRoom->addEnemy(Enemy("Bot", 20, 5, 8));

    currentRoom = adventure.createRoom("Flush Factory", "Un lugar industrial con un montón de recursos.");
    currentRoom->addEnemy(Enemy("Slurp Blob", 30, 8, 10));

    currentRoom = adventure.createRoom("Loot Lake", "Un lago rodeado de misterio y enigmas.");
    currentRoom->addItem(Item("Llave de boveda", "Abre una puerta especial al bunker secreto", Item::ItemType::KEY));
    currentRoom->addEnemy(Enemy("Guard", 25, 6, 10));

    currentRoom = adventure.createRoom("Polar Peak", "La cima de una montaña nevada.");
    currentRoom->addEnemy(Enemy("Trog", 35, 7, 10));

    currentRoom = adventure.createRoom("Misty Meadows", "Un campo lleno de vegetación y animales salvajes.");
    currentRoom->addEnemy(Enemy("Dire", 40, 9, 10));

    currentRoom = adventure.createRoom("The citadel", "Una ciudadela medieval llena de historia.");
    currentRoom->addItem(Item("Ex-caliber", "Un arma explosiva a distancia", Item::ItemType::WEAPON));

    currentRoom = adventure.createRoom("Tilted Towers", "Escapa rapido no puedes estar aqui mucho tiempo!");
    currentRoom->addEnemy(Enemy("Tryhard", 100, 15, 20));

    std::cout << "Bienvenido, " << player.getName() << ", a la Aventura de Fortnite!\n";

    while (true) {
        currentRoom->describeRoomState();

        if (currentRoom->isFinalRoom()) {
            std::cout << "Has llegado a la fase final! Has escapado de la isla!\n";
            std::cout << "Fin!\n";
            break;
        }

        std::cout <<
            "Que gustarias hacer en este momento?\n"
            " 1. Ver lugar\n"
            "2. Recoger loot\n"
            "3. Enfrentar enemigos\n"
            "4. Cambiar de lugar\n"
            "5. Salir :\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Analizando lugar...\n";
            currentRoom->describeRoomState();
            break;

        case 2:
            std::cout << "Recogiendo loot...\n";
            if (!currentRoom->getItems().empty()) {
                std::cout << "Elige un item que quieras recoger:\n";
                int index = 1;
                for (const auto& item : currentRoom->getItems()) {
                    std::cout << index << ". " << item.getName() << " - " << item.getDescription() << "\n";
                    index++;
                }
                int itemChoice;
                std::cin >> itemChoice;

                if (itemChoice >= 1 && itemChoice <= currentRoom->getItems().size()) {
                    player.pickUpItem(currentRoom->getItems()[itemChoice - 1]);
                    std::cout << "Has recogido " << currentRoom->getItems()[itemChoice - 1].getName() << "!\n";
                    currentRoom->removeItem(currentRoom->getItems()[itemChoice - 1].getName());
                }
                else {
                    std::cout << " item no valido.\n";
                }
            }
            else {
                std::cout << "No hay loot en este lugar.\n";
            }
            break;

        case 3:
            std::cout << "Enfrentando enemigos...\n";
            if (!currentRoom->getEnemies().empty()) {
                std::cout << "Elige al enemigo a atacar:\n";
                int index = 1;
                for (const auto& enemy : currentRoom->getEnemies()) {
                    std::cout << index << ". " << enemy.getName() << " (HP: " << enemy.getHealth() << ")\n";
                    index++;
                }
                int enemyChoice;
                std::cin >> enemyChoice;

                if (enemyChoice >= 1 && enemyChoice <= currentRoom->getEnemies().size()) {
                    player.attack(currentRoom->getEnemies()[enemyChoice - 1]);

                    for (auto& enemy : currentRoom->getEnemies()) {
                        enemy.attack(player);
                    }
                }
                else {
                    std::cout << "Seleccion de enemigo no permitida.\n";
                }
            }
            else {
                std::cout << "No hay enemigos en esta lugar.\n";
            }
            break;

        case 4:
            std::cout << "Cambiando de lugar...\n";
            currentRoom = adventure.changeRoom(currentRoom);
            break;
        case 5:
            std::cout << "Saliendo del juego. Nos vemos en el siguiente bus de batalla!\n";
            return 0;
        default:
            std::cout << "Opcion no valida.\n";
        }
    }

    return 0;
}