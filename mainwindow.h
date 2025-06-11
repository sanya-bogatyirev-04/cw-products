#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "table.hpp"
#include "comboBox.hpp"
#include "find.h"

#include <QMainWindow>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Find;

/**
 * @brief Главное окно приложения
 * @details Содержит таблицу с данными и элементы управления для работы с файлами,
 *          а также функции для перевода интерфейса и управления состоянием приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор главного окна
     * @param parent Родительский виджет
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор главного окна
     * @details Освобождает ресурсы, связанные с пользовательским интерфейсом.
     */
    ~MainWindow();

    /**
     * @brief Переводит интерфейс окна
     * @details Обновляет все текстовые элементы интерфейса согласно текущему языку.
     */
    void retranslate();

    /**
     * @brief Устанавливает новое имя окна
     * @details Формирует название окна на основе имени открытого файла и состояния изменений.
     */
    void setNewWindowTitle();

    /// Оригинальное название окна (когда файл не открыт)
    QString originalTitle = "";

protected:
    /**
     * @brief Обработчик события закрытия окна
     * @param event Событие закрытия окна
     * @details Запрашивает подтверждение перед закрытием и предлагает сохранить изменения.
     */
    void closeEvent(QCloseEvent *event) override;

private slots:
    /**
     * @brief Создает новый файл
     */
    void on_actionNew_triggered();

    /**
     * @brief Открывает существующий файл
     */
    void on_actionOpen_triggered();

    /**
     * @brief Закрывает текущий файл
     */
    void on_actionClose_triggered();

    /**
     * @brief Выход из приложения
     */
    void on_actionExit_triggered();

    /**
     * @brief Сохраняет файл по текущему пути
     */
    void on_actionSave_triggered();

    /**
     * @brief Сохраняет файл с выбором пути
     */
    void on_actionSave_as_triggered();

    /**
     * @brief Добавляет новую строку в таблицу
     */
    void on_actionAdd_row_triggered();

    /**
     * @brief Удаляет строку из таблицы
     */
    void on_actionRemove_row_triggered();

    /**
     * @brief Открывает окно поиска
     */
    void on_actionFind_triggered();

    /**
     * @brief Копирует выделенную строку
     */
    void on_actionCopy_row_triggered();

    /**
     * @brief Вырезает выделенную строку
     */
    void on_actionCut_row_triggered();

    /**
     * @brief Вставляет строку из буфера
     */
    void on_actionPaste_row_triggered();

    /**
     * @brief Показывает контекстное меню
     * @param pos Позиция для отображения меню
     */
    void showCustomContextMenu(const QPoint& pos);

    /**
     * @brief Открывает окно "Об авторе"
     */
    void on_actionAutor_triggered();

    /**
     * @brief Устанавливает русский язык интерфейса
     */
    void on_actionRussian_triggered();

    /**
     * @brief Устанавливает английский язык интерфейса
     */
    void on_actionEnglish_triggered();

    /**
     * @brief Отменяет сортировку таблицы
     */
    void on_actionSortDeny_triggered();

    /**
     * @brief Обрабатывает запрос фильтрации таблицы
     * @param column Столбец для фильтрации
     * @param filter Регулярное выражение для фильтрации
     */
    void findHandler(int column, const QString& filter);

    /**
     * @brief Обрабатывает закрытие окна поиска
     */
    void findCloseHandler();

    /**
     * @brief Обрабатывает изменение данных в модели
     */
    void modelDataChanged();

    /**
     * @brief Обновляет заголовки таблицы
     */
    void updateTableHeaders();

private:
    /**
     * @brief Сохраняет файл
     * @param filePath Путь для сохранения
     * @return Успешность операции
     */
    bool savefile(QString filePath);

    /**
     * @brief Загружает файл
     * @param filePath Путь к файлу
     * @return Успешность операции
     */
    bool loadfile(QString filePath);

    /**
     * @brief Устанавливает состояние интерфейса в зависимости от открытия файла
     * @param opened Флаг открытия файла
     */
    void setStateWhenFileOpened(bool opened);

    /**
     * @brief Предлагает сохранить файл при наличии изменений
     * @return Результат выбора пользователя
     */
    bool suggestSaveFile();

    /**
     * @brief Заполняет делегаты ComboBox данными
     */
    void fillDelegate();

    /**
     * @brief Меняет язык интерфейса
     * @param locale Новый язык
     */
    void changeLanguage(QString locale);

    /**
     * @brief Создает регулярное выражение для фильтрации
     * @param data Строка для фильтрации
     * @return Регулярное выражение
     */
    QRegularExpression handleSortData(const QString &data);

    /**
     * @brief Загружает настройки приложения
     */
    void loadSettings();

    /**
     * @brief Сохраняет настройки приложения
     */
    void saveSettings();

    /**
     * @brief Устанавливает стандартные размеры заголовков
     */
    void setDefaultHeadersSizes();

private:
    Ui::MainWindow *ui;                   ///< Указатель на интерфейс
    MyTableModel *model;                  ///< Модель данных таблицы
    QSortFilterProxyModel *sortmodel;     ///< Модель для сортировки и фильтрации
    Find *find;                           ///< Окно поиска
    QString openedPath = "";              ///< Путь к текущему файлу
    bool somethingMightChanged = false;   ///< Флаг изменений
    ComboBox *delegateFinansing;          ///< Делегат для столбца финансирования
    ComboBox *delegateActive;             ///< Делегат для столбца статуса
};

#endif // MAINWINDOW_H
