/*! \file utils.h
*  \brief Заголовочный файл с утилитарными функциями
 *  \details Содержит объявления вспомогательных функций для создания альбомов,
 *           валидации паролей и email-адресов.
 */
#ifndef UTILS
#define UTILS

#include <memory>
#include <string>
#include <vector>
#include <regex>
#include "../BaseClasses/album.h"
#include "album_type.h"

/*! \brief Фабрика для создания объектов альбомов
 *  \param type Тип создаваемого альбома
 *  \param albumTitle Название альбома
 *  \param tracks Вектор треков для добавления в альбом
 *  \return Умный указатель на созданный объект альбома
 *  \details Создает и возвращает объект альбома указанного типа с заданным названием и треками.
 *           Использует паттерн "Фабрика" для инкапсуляции логики создания различных типов альбомов.
 */
std::shared_ptr<Album> AlbumFactory(AlbumType type,
                                    const std::string& albumTitle,
                                    const std::vector<Track>& tracks);

/*! \brief Валидатор пароля
 *  \param password Пароль для проверки
 *  \return true если пароль соответствует требованиям безопасности, false в противном случае
 *  \details Проверяет пароль на соответствие требованиям безопасности, таким как минимальная длина,
 *           наличие цифр, заглавных и строчных букв, специальных символов.
 */
bool PasswordValidator(const std::string& password);

/*! \brief Валидатор email-адреса
 *  \param email Email-адрес для проверки
 *  \return true если email соответствует стандартному формату, false в противном случае
 *  \details Проверяет email-адрес на соответствие стандартному формату с использованием регулярных выражений.
 */
bool EmailValidator(const std::string& email);

#endif
