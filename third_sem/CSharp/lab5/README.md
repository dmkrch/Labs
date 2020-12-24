# Лабораторная работа №5(+ 1,2,3,4)

## Задание
```
Создать новую службу, которая на основе данных из базы данных (в моем случае Northwind) 
считывает определенную модель и создает xml файл, содержащий эти данные.
Так же нужно использовать службу из 3 лабы, которая отслеживает добавление новых файлов
в clientDirectory, делает нужные действия и переносит в targetDirectory
```

## Реализация
### Структура проекта
![Image alt](https://github.com/dmkrch/Labs/blob/master/third_sem/CSharp/lab5/images/projectStructure.png)
---

  ### Подробнее о структуре:
- ***ConfigurationManager*** - библиотека для конфигурации, разработанная в 3 лабе.

- ***FileManager*** - служба из прошлой рабораторной, которая отслеживает добавление файлов в clientDirectory, делает нужные действия и кидает в targetDirectory

- ***FileOperations*** - библиотека для различных операций с файлами.

- ***Northwind.DataAccessLayer*** - слой работы с базой данных. В библиотеке есть 2 папки: interfaces и implementations, для адекватного разделения интерфейсов и их реализации.

- ***Northwind.DataManagerService*** - собственно новая служба, которая генерит xml файл на основе данных и кидает его в clientDirectory

- ***Northwind.Models*** - библиотека для моделей службы. Там есть модели заказа и ошибки.

- ***Nortwind.ServiceLayer*** - слой для работы с DataAccessLayer. Библиотека ServiceLayer содержит 2 папки: interfaces и implementations, для адекватного разделения интерфейсов и их реализации.

- ***configs*** - содержит файлы конфигурации, с которых берутся опции, необходимые как для службы FileManager, так и для Northwind.DataManager

- ***procedures*** - содержит процедуры-запросы, которые необходимы для получения набора данных из бд Northwind. Там лежит 3 процедуры - достать заказ по id, достать 30 заказов, отправить сообщение об ошибке в отдельную базу данных (ExceptionsDB)
---
## Как работает служба DataManagerService:
### Главный метод службы - OnStart(args) работает в условных 4 этапа:
```
1. Происходит конфигурация опций, нужных для DataManagerService: Сначала
устанавливается парсер для ConfiguratonManager, затем в глобальный объект
options грузятся данные из xml-файла (configs/DataManagerConfig.xml)
![Image alt](https://github.com/dmkrch/Labs/blob/master/third_sem/CSharp/lab5/images/managerConfig.png)

2. Получение моделей заказов из базы данных в коллекцию ordersInfo
![Image alt](https://github.com/dmkrch/Labs/blob/master/third_sem/CSharp/lab5/images/gettingOrderList.png)

3. Формирование имени xml файла на основе текущего времени
![Image alt](https://github.com/dmkrch/Labs/blob/master/third_sem/CSharp/lab5/images/xmlFileName.png)

4. Создание xml файла, на основе коллекции ordersInfo и имени файла,
который нужно создать
![Image alt](https://github.com/dmkrch/Labs/blob/master/third_sem/CSharp/lab5/images/generateXml.png)
```
