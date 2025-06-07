#ifndef DATA_HPP
#define DATA_HPP

#include <QString>

/**
 *   Data
 *   Хранит информацию об отдельной записи в таблице
 */
class Data
{
private:
    ///   Хранит ID
    unsigned int id;

    ///   Хранит название
    QString name;

    ///   Хранит тип изделия
    QString type;

    ///   Хранит марки изделий
    QString mark;

    ///   Хранит длину
    double length;

    ///   Хранит ширину
    double  width;

    ///   Хранит вес одного изделия
    double weight;

    ///   Хранит тип арматуры
    QString fittings;

    ///   Хранит дату изготовления
    QString date;

public:
    /**
     *    Конструктор по умолчанию
     *    Создает пустую запись
     */
    Data();

    ///   Конструктор с заранее определенными параметрами
    Data(int id,
                QString &name,
                QString &type,
                QString &mark,
                double length,
                double width,
                double weight,
                QString &fittings,
                QString &date);
    ///   Конструктор копирования
    Data(const Data&other);

    ///   Конструктор из строки
    Data(QString splitLine);

    ///   Перегрузка оператора присваивания
    Data &operator=(const Data&other);

    /**
     *   Метод для получения информации о записи в формате строки
     *  Строка c информацией о записи, столбцы разделены точкой с запятой
     */
    QString getSplitString();

    ///   Деструктор по умолчанию
    ~Data();

    /**
     *   Метод, устанавливающий код записи
     *   id код записи
     */
    void setID(const int id);

    /**
     *   Метод, устанавливающий название
     *   name название
     */
    void setName(const QString &name);

    /**
     *   Метод, устанавливающий тип изделия
     *   type тип изделия
     */
    void setType(const QString &type);

    /**
     *   Метод, устанавливающий марку изделия
     *   mark марка изделия
     */
    void setMark(const QString &mark);

    /**
     *   Метод, устанавливающий длину
     *   length длина
     */
    void setLength(const double length);

    /**
     *   Метод, устанавливающий ширину
     *   width ширина
     */
    void setWidth(const double width);


    /**
     *   Метод, устанавливающий вес
     *   weight вес
     */
    void setWeight(const double weight);


    /**
     *   Метод, устанавливающий тип арматуры
     *   fittings тип арматуры
     */
    void setFittings(const QString &fittings);

    /**
     *   Метод, устанавливающий дату производста
     *   date дата производства
     */
    void setDate(const QString &date);

    ///   Метод, возвращающий код записи
    int getID() const;

    ///   Метод, возвращающий название
    QString getName() const;

    ///   Метод, возвращающий тип изделия
    QString getType() const;

    ///   Метод, возвращающий марку изделия
    QString getMark() const;

    ///   Метод, возвращающий длину
    double getLenght() const;

    ///   Метод, возвращающий ширину
    double getWidth() const;

    ///   Метод, возвращающий вес
    double getWeight() const;

    ///   Метод, возвращающий тип арматуры
    QString getFittings() const;

    ///   Метод, возвращающий дату производства
    QString getDate() const;

    ///   Метод, проверяющий пустая ли запись
    bool isEmpty();
};
#endif // DATA_HPP
