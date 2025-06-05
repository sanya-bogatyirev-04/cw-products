#include "data.hpp"
#include "math.h"

Data::Data():
    id(),
    name(),
    type(),
    mark(),
    length(),
    width(),
    weight(),
    fittings(),
    date()
{}

Data::Data(int id, QString &name, QString &type,
                         QString  &mark, double length, double width, double weight,
                         QString &fittings, QString &date):
    id(id),
    name(name),
    type(type),
    mark(mark),
    length(length),
    width(width),
    weight(weight),
    fittings(fittings),
    date(date)
{}

Data::Data(const Data &other)
{
    id = other.id;
    name = other.name;
    type = other.type;
    mark = other.mark;
    length = other.length;
    width = other.width;
    weight = other.weight;
    fittings = other.fittings;
    date = other.date;
}

Data::Data(QString splitLine)
{
    id = splitLine.mid(0, splitLine.indexOf(';')).toInt(); splitLine.remove(0, splitLine.indexOf(';') + 1);
    name = splitLine.mid(0, splitLine.indexOf(';')); splitLine.remove(0, splitLine.indexOf(';') + 1);
    type = splitLine.mid(0, splitLine.indexOf(';'));splitLine.remove(0, splitLine.indexOf(';') + 1);
    mark = splitLine.mid(0, splitLine.indexOf(';')); splitLine.remove(0, splitLine.indexOf(';') + 1);
    length = splitLine.mid(0, splitLine.indexOf(';')).toDouble(); splitLine.remove(0, splitLine.indexOf(';') + 1);
    width = splitLine.mid(0, splitLine.indexOf(';')).toDouble(); splitLine.remove(0, splitLine.indexOf(';') + 1);
    weight= splitLine.mid(0, splitLine.indexOf(';')).toDouble(); splitLine.remove(0, splitLine.indexOf(';') + 1);
    fittings = splitLine.mid(0, splitLine.indexOf(';')); splitLine.remove(0, splitLine.indexOf(';') + 1);
    date = splitLine.mid(0, splitLine.indexOf(';')); splitLine.remove(0, splitLine.indexOf(';') + 1);
}

Data &Data::operator=(const Data &other)
{
    if (this == &other) return *this;

    id = other.id;
    name = other.name;
    type = other.type;
    mark = other.mark;
    length = other.length;
    width = other.width;
    weight = other.weight;
    fittings = other.fittings;
    date = other.date;

    return *this;
}

QString Data::getSplitString()
{
    QString splitString;

    splitString += QString::number(this->getID()) + ";";
    splitString += this->getName() + ";";
    splitString += this->getType() + ";";
    splitString += this->getMark() + ";";
    splitString += QString::number(this->getLenght()) + ";";
    splitString += QString::number(this->getWidth()) + ";";
    splitString += QString::number(this->getWeight()) + ";";
    splitString += this->getFittings() + ";";
    splitString += this->getDate() + ";";

    return splitString;
}

Data::~Data()
{}

void Data::setID(const int id) {this->id = std::abs(id);}
void Data::setName(const QString &name) {this->name = name;}
void Data::setType(const QString &type) {this->type = type;}
void Data::setMark(const QString &mark) {this->mark = mark;}
void Data::setLength(const double length) {this->length = fabs(length);}
void Data::setWidth(const double width) {this->width = fabs(width);}
void Data::setWeight(const double weight) {this->weight = fabs(weight);}
void Data::setFittings(const QString &fittings) {this->fittings =fittings;}
void Data::setDate(const QString &date) {this->date =date;}

int Data::getID() const {return id;}
QString Data::getName() const {return name;}
QString Data::getType() const {return type;}
QString Data::getMark() const {return mark;}
double Data::getLenght() const {return length;}
double Data::getWidth() const {return width;}
double Data::getWeight() const {return weight;}
QString Data::getFittings() const {return fittings;}
QString Data::getDate() const {return date;}

bool Data::isEmpty()
{
    if(this->getID() != 0) return false;
    if(this->getName() != "") return false;
    if(this->getType() != "") return false;
    if(this->getMark() != "") return false;
    if(this->getLenght() != 0) return false;
    if(this->getWidth() != 0) return false;
    if(this->getWeight() != 0) return false;
    if(this->getFittings() != "") return false;
    if(this->getDate() != "") return false;
    return true;
}
