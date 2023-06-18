//
// Created by maksi on 09.06.2023.
//

#ifndef BND_BNDMETHODS_HPP
#define BND_BNDMETHODS_HPP

#include "dto/BND.h"
namespace BNDNS {
    /**
    * @class BNDCommand
    * @brief Абстрактный базовый класс BNDCommand
    */
    class BNDCommand {
    public:
        /**
        * @brief Объявление чисто виртуальной функции execute
        */
        virtual void execute() = 0;

        BND &bnd;/**< Объявление ссылки на объект класса BND*/

        /**
        * @brief Конструктор класса BNDCommand с параметрами
        * @param bnd Ссылка на объект класса BND
        */
        explicit BNDCommand(BND &bnd);
        /**
        * @brief Виртуальный деструктор класса BNDCommand
        */
        virtual ~BNDCommand();
    };
}
#endif //BND_BNDMETHODS_HPP
