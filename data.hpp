#ifndef DATA_HPP
#define DATA_HPP

#include <QString>

/**
 * @brief Класс для хранения данных одной записи таблицы
 * @details Содержит информацию о строительных изделиях: марку, размеры, вес, дату производства и др.
 */
class Data
{
private:
    unsigned int id;      ///< Уникальный идентификатор записи
    QString name;         ///< Наименование изделия
    QString type;         ///< Тип изделия
    QString mark;         ///< Марка изделия
    double length;        ///< Длина изделия (в метрах)
    double width;         ///< Ширина изделия (в метрах)
    double weight;        ///< Вес изделия (в кг)
    QString fittings;     ///< Тип арматуры
    QString date;         ///< Дата производства (в формате "dd.MM.yyyy")

public:
    /**
     * @brief Конструктор по умолчанию
     * @details Создает пустую запись с нулевыми значениями.
     */
    Data();

    /**
     * @brief Конструктор с параметрами
     * @param id Идентификатор записи
     * @param name Наименование изделия
     * @param type Тип изделия
     * @param mark Марка изделия
     * @param length Длина изделия
     * @param width Ширина изделия
     * @param weight Вес изделия
     * @param fittings Тип арматуры
     * @param date Дата производства
     */
    Data(int id,
         QString &name,
         QString &type,
         QString &mark,
         int length,
         int width,
         double weight,
         QString &fittings,
         QString &date);

    /**
     * @brief Конструктор копирования
     * @param other Объект для копирования
     */
    Data(const Data &other);

    /**
     * @brief Конструктор из строки
     * @details Разбирает строку формата "id;name;type;...;date" на поля класса.
     * @param splitLine Входная строка данных
     */
    Data(QString splitLine);

    /**
     * @brief Перегрузка оператора присваивания
     * @param other Объект для копирования
     * @return Ссылка на текущий объект
     */
    Data &operator=(const Data &other);

    /**
     * @brief Преобразует данные в строку
     * @details Формат: "id;name;type;...;date"
     * @return Строка с данными, разделенными точкой с запятой
     */
    QString getSplitString();

    /// @brief Деструктор (по умолчанию)
    ~Data();

    /**
     * @brief Устанавливает идентификатор записи
     * @param id Новый идентификатор
     */
    void setID(const int id);

    /**
     * @brief Устанавливает наименование изделия
     * @param name Новое наименование
     */
    void setName(const QString &name);

    /**
     * @brief Устанавливает тип изделия
     * @param type Новый тип
     */
    void setType(const QString &type);

    /**
     * @brief Устанавливает марку изделия
     * @param mark Новая марка
     */
    void setMark(const QString &mark);

    /**
     * @brief Устанавливает длину изделия
     * @param length Новая длина
     */
    void setLength(const int length);

    /**
     * @brief Устанавливает ширину изделия
     * @param width Новая ширина
     */
    void setWidth(const int width);

    /**
     * @brief Устанавливает вес изделия
     * @param weight Новый вес
     */
    void setWeight(const double weight);

    /**
     * @brief Устанавливает тип арматуры
     * @param fittings Новый тип арматуры
     */
    void setFittings(const QString &fittings);

    /**
     * @brief Устанавливает дату производства
     * @param date Новая дата
     */
    void setDate(const QString &date);

    /**
     * @brief Возвращает идентификатор записи
     * @return Текущий идентификатор
     */
    int getID() const;

    /**
     * @brief Возвращает наименование изделия
     * @return Текущее наименование
     */
    QString getName() const;

    /**
     * @brief Возвращает тип изделия
     * @return Текущий тип
     */
    QString getType() const;

    /**
     * @brief Возвращает марку изделия
     * @return Текущая марка
     */
    QString getMark() const;

    /**
     * @brief Возвращает длину изделия
     * @return Текущая длина
     */
    int getLenght() const;

    /**
     * @brief Возвращает ширину изделия
     * @return Текущая ширина
     */
    int getWidth() const;

    /**
     * @brief Возвращает вес изделия
     * @return Текущий вес
     */
    double getWeight() const;

    /**
     * @brief Возвращает тип арматуры
     * @return Текущий тип арматуры
     */
    QString getFittings() const;

    /**
     * @brief Возвращает дату производства
     * @return Текущая дата
     */
    QString getDate() const;

    /**
     * @brief Проверяет, является ли запись пустой
     * @return true, если запись пуста, иначе false
     */
    bool isEmpty();
};

#endif // DATA_HPP
