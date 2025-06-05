#include "grapf.h"
#include "ui_grapf.h"

#include <QPainter>
#include <QCloseEvent>

Grapf::Grapf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grapf)
{
    ui->setupUi(this);
    orginalTitle = this->windowTitle();
}

void Grapf::closeEvent(QCloseEvent *event)
{
    emit grapfClosed(); // Издаем сигнал о том что график закрылся
    event->accept(); // Принимаем событие закрытия окна
}

Grapf::~Grapf()
{
    delete ui; // Освобождаем память от окна
}

void Grapf::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    int indent = 50; // Задаем отступы от краев
    setFixedSize(data.count() * 80 + 2 * indent , 400); // Задаем размер окна, зависящего от кол-ва уникльных записей

    QPainter painter(this); // Создаем объект пэинтера, который будет рисовать на текущем окне

            int width = this->width(); // Ширина окна
            int height = this->height(); // ВЫсота окна

            int grapfBoxWidth = width - 2 * indent; // Ширина области для рисования с учетом отступов
            int grapfBoxHeight = height - 2 * indent; // Высота области для рисования с учетом отступом
            int grapfSegmentWidth = grapfBoxWidth / data.size(); // Ширина столбца графика

            // Ищем максимальное значение потраченной суммы
            double maxValue = 0;
            for (auto value : data.values()) // Перебор значений словаря
                if (value > maxValue)
                    maxValue = value;

            QBrush brush; // Объект стиля закрашивания
            brush.setStyle(Qt::SolidPattern); // Устанавливаем сплошное закрашивание

            int columnIndex = 0;
            for (const auto& pair : data.toStdMap()) // Перебор по ключам и значениям
            {
                const QString& key = pair.first; // Ключ - тип
                const int& value = pair.second; // Значение - длина

                // Обеспечиваем чередование фиолетового и синего столбца графика
                if(columnIndex % 2 == 0) brush.setColor(Qt::darkRed);
                else brush.setColor(Qt::darkYellow);

                int barHeight = (float)value / maxValue * grapfBoxHeight; // Получаем высоту текущего стобца, относительно самого высокого столбца, выщетанного ранее

                // Отрисовываем столбец
                QRect barRect(indent + columnIndex * grapfSegmentWidth, // Координата верхней левой точкой по OX
                              indent + grapfBoxHeight - barHeight, // Координата верхней левой точкой по OY
                              grapfSegmentWidth - 2, // Длина
                              barHeight); // Высота

                painter.fillRect(barRect, brush); // Закрашиваем

                // Подписываем текущий столбец графика должностью снизу
                painter.drawText(indent + columnIndex * grapfSegmentWidth,
                                 height - indent + 5,
                                 grapfSegmentWidth,
                                 20,
                                 Qt::AlignCenter,
                                 key);

                // Подписываем текущий столбец графика зарплатой сверху
                painter.drawText(indent + columnIndex * grapfSegmentWidth,
                                 indent + grapfBoxHeight - barHeight - 20,
                                 grapfSegmentWidth,
                                 20,
                                 Qt::AlignCenter,
                                 QString::number(value) + "M");
                columnIndex++;
            }

            // Рисуем полосу под графиком, символизитрующую OX
            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine(indent - 1, height - indent, width - indent - 2, height - indent);
        }

void Grapf::insertIntoMap(QString type, double length)
{
    if(data.contains(type)) {
        data[type] = length;  // Если словарь содержит такой ключ
    }
    else {
        data[type] = length;  // Иначе создаем новый ключ с исходным значением
    }
}

void Grapf::dropMapData()
{
    data.clear(); // Очищаем данные

}

void Grapf::retranslate()
{
    ui->retranslateUi(this);    // Переводим интерфейс
    orginalTitle = this->windowTitle(); // Сохраняем новое переведенное исходное название окна
}

void Grapf::setNewWindowName(QString parentPart)
{
    // Формируем новое название окна
    QString windowname = orginalTitle + tr(" for ");
    windowname += parentPart;
    setWindowTitle(windowname);

}
