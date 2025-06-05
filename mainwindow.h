#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "table.hpp"
#include "comboBox.hpp"
#include "grapf.h"
#include "find.h"

#include <QMainWindow>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Find;
class Grapf;

/**
  *   MainWindow
  *   Собственная реализация класса QMainWindow.
  *   Отвечает за работу главного окна приложения.
  */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///   Конструктор по умолчанию
    MainWindow(QWidget *parent = nullptr);

    ///   Деструктор по умолчанию
    ~MainWindow();

    /**
      *   Метод retranslate
      *   Переводит интерфейс окна
      */
    void retranslate();

    /**
      *   Метод setNewWindowTitle
      *   Устанавливает новое имя окна в зависимости от открытого файла и факта его измененности
      */
    void setNewWindowTitle();

    ///   Хранит оригинальное название окна (Название в состоянии когда файл не открыт)
    QString originalTitle = "";

protected:
    /**
     *   Обработчик события закрытия окна.
     *   Просит подтверждение перед закрытием окна и предлагаем сохранить файл, если были изменения
     *   event Событие закрытия окна.
     */
    void closeEvent(QCloseEvent *event) override;

private slots:
    ///  Слот-обработчик создания нового файла в приложении.
    void on_actionNew_triggered();

    ///  Слот-обработчик открытия существующего файла в приложении.
    void on_actionOpen_triggered();

    ///  Слот-обработчик закрытия открытого в приложении файла.
    void on_actionClose_triggered();

    ///  Слот-обработчик выхода из приложения.
    void on_actionExit_triggered();

    ///  Слот-обработчик сохранения файла по открытому пути.
    void on_actionSave_triggered();

    ///  Слот-обработчик сохранения файла по выбранному пользователем пути.
    void on_actionSave_as_triggered();

    ///  Слот-обработчик добавления новой строки в таблицу.
    void on_actionAdd_row_triggered();

    ///  Слот-обработчик удаления строки из таблицы.
    void on_actionRemove_row_triggered();

    ///  Слот-обработчик фильтрации(поиска) по таблице.
    void on_actionFind_triggered();

    ///  Слот-обработчик копирования выделенной строки в буфер обмена.
    void on_actionCopy_row_triggered();

    ///  Слот-обработчик вырезания выделенной строки в буфер обмена.
    void on_actionCut_row_triggered();

    ///  Слот-обработчик вставки строки в таблицу.
    void on_actionPaste_row_triggered();

    /**
     *   Слот-обработчик отображения контекстного меню.
     *   pos Координаты, где будет показано контекстное меню.
    */
    void showCustomContextMenu(const QPoint& pos);

    ///  Слот-обработчик вызова окна "Об авторе".
    void on_actionAutor_triggered();

    ///  Слот-обработчик установки Русского языка.
    void on_actionRussian_triggered();

    ///  Слот-обработчик установки Английского языка.
    void on_actionEnglish_triggered();

    ///  Слот-обработчик отмены сортировки.
    void on_actionSortDeny_triggered();

    /**
     *   Слот-обработчик запроса фильтрации(поиска) по таблице
     *   column Столбец, по которому необходимо осуществить фильтрацию
     *   filter регулярное выражение, применяемое для фильтрации
    */
    void findHandler(int column, const QString& filter);

    /**
     *   Слот-обработчик закрытия окна поиска.
     *   Отменяет активную фильтрацию.
    */
    void findCloseHandler();

    ///   Слот-обработчик открытия нового главного окна приложения.
    void on_actionNew_window_triggered();

    /**
    *   Слот-обработчик изменения данных в модели.
    *   Меняет имя окна в состояние, что файл изменен, если открыт график, обновляет его и устанавливает значение, что файл быз изменен
    */
    void modelDataChanged();

    ///   Слот-обработчик открытия окна с графиком.
    void on_actionGrapf_triggered();

    /**
     *   Слот-обработчик для обновления заголовков таблицы.
     *   Вызывает обновление заголовков модели при смене языка.
     */
    void updateTableHeaders();

private:
    /**
      *   Метод сохранения файла.
      *   filePath Путь, куда нужно сохранить файл.
      *   bool успешно ли сохранен файл
     */
    bool savefile(QString filePath);

    /**
      *   Метод сохранения файла.
      *   filePath Путь, куда нужно откуда нужно загрузить файл.
      *   bool успешно ли открыт файл
     */
    bool loadfile(QString filePath);

    /**
     *   Метод установки интерфейса в положение, открыт или нет файл
     */
    void setStateWhenFileOpened(bool);

    /**
     *   Метод предлагающий сохранить файл
     *   bool, где false - пользователь отменет любое действие следующие за предложением сохранить файл
     */
    bool suggestSaveFile();

    /**
     *   Метод заполняющий delegate комбобоксы нужными данными
     */
    void fillDelegate();

    /**
     *   Метод, меняющий язык интерфейса
     *   locale на которую нужно сменить язык
     */
    void changeLanguage(QString locale);

    /**
     *   Метод создающий регулярное выражение для фильтрации
     *   data строка, основе которой нужно создать выражение для фильтрации
     *   Регулярное выражение для фильтрации
     */
    QRegularExpression handleSortData(const QString &data);

    /**
     *   Метод, загружающий настройки
     */
    void loadSettings();

    /**
     *   Метод, сохраняющий настройки
     */
    void saveSettings();

    /**
     *   Метод, ставящий горизонтальным заголовкам стандартную(заготовленную) ширину
     */
    void setDefaultHeadersSizes();

private:
    ///   Cсылка на интерфейс класса
    Ui::MainWindow *ui;

    ///   Ссылка на хранение модель для tableview
    MyTableModel *model;

    ///   Ссылка на модель для фильтрации и сортировки
    QSortFilterProxyModel *sortmodel;

    ///   Ссылка на окно для поиска
    Find *find;

    ///   Ссылка на окно для графика
    Grapf *grapf;

    ///   Строка, хранящая путь к текущему открытому файлу
    QString openedPath = "";

    ///   Bool, отмечающий, были ли изменения в файле
    bool somethingMightChanged = false;

    ///   Bool, говорящий, открыто ли окно графика
    bool grapfActive = false;

    ///   Ссылка на делегат для столбца финансирования
    ComboBox *delegateFinansing;

    ///   Ссылка на делегат для столбца статус
    ComboBox *delegateActive;
};
#endif // MAINWINDOW_H
