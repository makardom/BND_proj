//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CREATE_HPP
#define BND_CREATE_HPP
#include "BNDCommand.hpp"
namespace BNDNS {
    /**
    * @class Create
    * @brief Создает библиотечный набор данных
    * @details Наследуется от класса BNDCommand
    */
    class Create : BNDCommand {
    private:
        unsigned short catAmount;/**< Количество разделов в БНД*/
        unsigned short catOffset;/**< Количество блоков, которое выделено для БНД (смещение до начала разделов БНД)*/
    public:
        /**
        * @brief Функция для создания БНД
        * @param bnd Ссылка на объект класса BND
        * @param amount Количество записей в каталоге
        * @param offset Смещение каталога
        */
        Create(BND &bnd, unsigned short amount, unsigned short offset);
        /**
        * @brief Объявление виртуальной функции
        */
        void execute() override;
        /**
        * @brief Деструктор класса Create
        */
        ~Create() override;
    };
}
#endif //BND_CREATE_HPP