#ifndef DATA_HPP
#define DATA_HPP

#include <QString>

/**
 * @class Data
 * @brief Хранит информацию об отдельной записи в таблице
 */
class Data
{
private:
    /// @brief Хранит ID
    unsigned int id;

    /// @brief Хранит название
    QString name;

    /// @brief Хранит тип изделия
    QString type;

    /// @brief Хранит марки изделий
    QString mark;

    /// @brief Хранит длину
    double length;

    /// @brief Хранит ширину
    double  width;

    /// @brief Хранит вес одного изделия
    double weight;

    /// @brief Хранит тип арматуры
    QString fittings;

    /// @brief Хранит дату изготовления
    QString date;

public:
    /**
     *  @brief Конструктор по умолчанию
     *  @details Создает пустую запись
     */
    Data();

    /// @brief Конструктор с заранее определенными параметрами
    Data(int id,
                QString &name,
                QString &type,
                QString &mark,
                double length,
                double width,
                double weight,
                QString &fittings,
                QString &date);
    /// @brief Конструктор копирования
    Data(const Data&other);

    /// @brief Конструктор из строки
    Data(QString splitLine);

    /// @brief Перегрузка оператора присваивания
    Data &operator=(const Data&other);

    /**
     * @brief Метод для получения информации о записи в формате строки
     * @return Строка c информацией о записи, столбцы разделены точкой с запятой
     */
    QString getSplitString();

    /// @brief Деструктор по умолчанию
    ~Data();

    /**
     * @brief Метод, устанавливающий код записи
     * @param id код записи
     */
    void setID(const int id);

    /**
     * @brief Метод, устанавливающий название
     * @param name название
     */
    void setName(const QString &name);

    /**
     * @brief Метод, устанавливающий тип изделия
     * @param type тип изделия
     */
    void setType(const QString &type);

    /**
     * @brief Метод, устанавливающий марку изделия
     * @param mark марка изделия
     */
    void setMark(const QString &mark);

    /**
     * @brief Метод, устанавливающий длину
     * @param length длина
     */
    void setLength(const double length);

    /**
     * @brief Метод, устанавливающий ширину
     * @param width ширина
     */
    void setWidth(const double width);


    /**
     * @brief Метод, устанавливающий вес
     * @param weight вес
     */
    void setWeight(const double weight);


    /**
     * @brief Метод, устанавливающий тип арматуры
     * @param fittings тип арматуры
     */
    void setFittings(const QString &fittings);

    /**
     * @brief Метод, устанавливающий дату производста
     * @param date дата производства
     */
    void setDate(const QString &date);

    /// @brief Метод, возвращающий код записи
    int getID() const;

    /// @brief Метод, возвращающий название
    QString getName() const;

    /// @brief Метод, возвращающий тип изделия
    QString getType() const;

    /// @brief Метод, возвращающий марку изделия
    QString getMark() const;

    /// @brief Метод, возвращающий длину
    double getLenght() const;

    /// @brief Метод, возвращающий ширину
    double getWidth() const;

    /// @brief Метод, возвращающий вес
    double getWeight() const;

    /// @brief Метод, возвращающий тип арматуры
    QString getFittings() const;

    /// @brief Метод, возвращающий дату производства
    QString getDate() const;

    /// @brief Метод, проверяющий пустая ли запись
    bool isEmpty();
};
#endif // DATA_HPP
