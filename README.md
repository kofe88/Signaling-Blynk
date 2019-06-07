# Signaling-Blynk
Signaling Arduino+esp8266+SIM800L+Blynk

![IMG_20190327_152148](https://user-images.githubusercontent.com/45194485/55217894-aa80cc00-5211-11e9-9fe6-9ef0c5320408.jpg)

Прошивка создана для платы из этого проекта: https://easyeda.com/MihAlex/signaling-Arduino-SIM800L
Плата постоянно совершенствуется, и может изменяться.
Более компактная версия платы https://easyeda.com/MihAlex/signaling-Arduino-SIM800L_copy

**Обновления:**

28/05/2019

Плата NodeMcu:
* оптимизировано создание кнопок при старте 
* оптимизирована отправка DTMF команд через терминал

Плата Ардуино:
* реализовано автоопределение подключенных модемов
* исправлен баг с постановкой/снятием с охраны звонком с номера USER
* добавлены новые DTMF команды
* добавлена функция электронных часов на индикаторе TM1637

### На печатной плате могут разместиться:

* Arduino Nano V3.0
* NodeMcu v3 для выхода в интернет.
* SIM800L для мобильной связи.
* Радиомодуль NRF24L01 для приёма сигналов от беспроводных датчиков.
* ИК-приёмник
* Датчик температуры DS18B20.
* Термистор.
* Микроволновый датчик движения RCWL-0516.
* 7 сигментный индикатор часов TM1637
* Зуммер.
* Микрофон.
* MOSFET транзисторы AO3400A для включения платы NodeMcu и внешних маломощных устройств.
* Разъёмы для подключения других датчиков
* Переключение на резервный источник питания

Кроме того, к свободным пинам могут подключаться любые другие ардуиносовместимые датчики и модули.

Cигнализация модульная, можно выбрать ту конфигурацию, которая нужна в данном случае. Она может работать с SIM800L или NodeMcu на выбор, либо с обоими модулями одновременно. В последнем случае имеет два независимых канала связи, что более надёжно.

### В состав проекта входят следующие скетчи:
* Скетч для Arduino Nano V3.0. Выполняет основные функции сигнализации.
https://github.com/wisenheimer/Signaling-Blynk/blob/master/Signalka/Signalka.ino
* Скетч для платы NodeMcu v3. Осуществляет управление Arduino через приложение на телефоне.
https://github.com/wisenheimer/Signaling-Blynk/tree/master/NodeMCU
* Скетч беспроводного датчика на модуле nRF24L01
https://github.com/wisenheimer/Signaling-Blynk/blob/master/nRF24sensor/nRF24sensor.ino
* Скетч беспроводного ИК-датчика
https://github.com/wisenheimer/Signaling-Blynk/blob/master/IRsensor/IRsensor.ino

## Необходимые библиотеки

Скачать последнюю Blynk library можно здесь:

https://github.com/blynkkk/blynk-library/releases/latest

Дополнительная информация о Blynk здесь:

Downloads, docs, tutorials: http://www.blynk.cc

Sketch generator:           http://examples.blynk.cc

Blynk community:            http://community.blynk.cc

Follow us:                  http://www.fb.com/blynkapp
                            http://twitter.com/blynk_app

Прошивка для NodeMcu написана в среде Arduino IDE. Чтобы собрать проект, необходимо установить библиотеку для ESP8266 от сюда https://github.com/esp8266/Arduino#available-versions
Ставим версию 2.4.2. С более новыми может не работать.

Библиотека 1-Wire
https://github.com/PaulStoffregen/OneWire

Для датчика температуры DS18B20 https://github.com/milesburton/Arduino-Temperature-Control-Library

Для радиомодуля nRF24L01 https://github.com/nRF24/RF24

Для ИК-датчика и ИК-приёмника https://github.com/z3t0/Arduino-IRremote

Для 7 сигментного индикатора TM1637 https://github.com/Seeed-Studio/Grove_4Digital_Display

Если при компиляции появляются непонятные ошибки, попробуйте сделать следующее:

    Tools > Board > Boards Manager

    Wait for downloads to finish.

    Click on "Arduino AVR Boards".

    Select 1.6.21 from the dropdown menu.

    Click "Install".

    Wait for installation to finish.

    Click "Close".

## Подключение 7 сигментного индикатора TM1637. Электронные часы

К плате Ардуино можно подключить 7 сигментный индикатор TM1637, на который будет выводиться текущее время.

![tm1637](https://user-images.githubusercontent.com/45194485/58461005-663d7980-8137-11e9-8519-d92f2782573f.jpg)

В файле настроек main_type/settings.h нужно разрешить его использование дефайном

>#define TM1637_ENABLE 1 // семисигментный индикатор для часов

И задать пины, к которым он будет подключен

>#define CLK 7         
>#define DIO 8

## Создание приложения Blynk для телефона

Для начала вам нужно скачать на свой телефон приложение Blynk для Arduino, ESP8266,RPi

IOS:

https://itunes.apple.com/us/app/blynk-control-arduino-raspberry/id808760481?ls=1&mt=8

Android:

https://play.google.com/store/apps/details?id=cc.blynk

Затем получить auth token.

Чтобы связать NodeMcu и приложение нам понадобится auth token, который нам вышлют на электронную почту.

Создайте новый аккаунт в приложении blynk.

![2](https://user-images.githubusercontent.com/45194485/55215558-44914600-520b-11e9-83ef-d56790a1d6a9.jpg)

Создайте новый проект. Выберите плату и тип подключения.

![3](https://user-images.githubusercontent.com/45194485/55215570-4a872700-520b-11e9-80d9-da4774018951.jpg)

После создания, auth token придет вам на email.

![4](https://user-images.githubusercontent.com/45194485/55215700-bc5f7080-520b-11e9-9ec5-0329a4cd24f8.jpg)

Добавляем себе виджет Terminal

![5](https://user-images.githubusercontent.com/45194485/55215784-00527580-520c-11e9-97f4-2049da615118.jpg)

Устанавливаем виртуальный пин V0. Переключатели как на фото.

![6](https://user-images.githubusercontent.com/45194485/55215829-1f510780-520c-11e9-97d4-02cd090b9f09.jpg)

Добавляем виджет Table.

![7](https://user-images.githubusercontent.com/45194485/55215895-48719800-520c-11e9-8fbc-186983fdd3b9.jpg)

Устанавливаем виртуальный пин V1, переключатели в положение YES.

![8](https://user-images.githubusercontent.com/45194485/55215983-8f5f8d80-520c-11e9-914e-e74b93e8b17d.jpg)

Размещаем удобно эти виджеты на экране, должно получиться примерно так:

![9](https://user-images.githubusercontent.com/45194485/55216022-af8f4c80-520c-11e9-938b-08773e5f7ba1.jpg)

В терминал будут выводиться сообщения сигнализации. Так же из него можно отправлять в сигнализацию команды управления.

О событиях будут сообщать следующие виджеты: Eventor, Notification, Email и Twitter.
Добавляем их:

![10](https://user-images.githubusercontent.com/45194485/55216112-f4b37e80-520c-11e9-946e-8cfcd0a7e015.jpg)

![11](https://user-images.githubusercontent.com/45194485/55216122-f715d880-520c-11e9-8aac-715401f1c9c2.jpg)

Добавляем новый Event. Устанавливаем виртуальный пин V2, прописываем условие срабатывания V2 is equal 1. Добавляем текст сообщения. Например ALARM.

![12](https://user-images.githubusercontent.com/45194485/55216239-42c88200-520d-11e9-9f8a-38703c935b06.jpg)

![13](https://user-images.githubusercontent.com/45194485/55216258-4bb95380-520d-11e9-95b7-fa88081e3f91.jpg)

Вписываем свой email, на который будут приходить сообщения от сигнализации.

![14](https://user-images.githubusercontent.com/45194485/55216266-51169e00-520d-11e9-9893-f00853ec8d8b.jpg)

В конце получаем следующее:

![15](https://user-images.githubusercontent.com/45194485/55217312-47db0080-5210-11e9-86b8-e4477b2298de.png)

## Настройка платы NodeMcu v3 после прошивки
Подключить плату к компьютеру. Открыть терминал для этой платы.
Перезагрузить плату нажатием кнопки RESET. При запуске нажать и удерживать кнопку FLASH до появления следующих сообщений в терминале

![18](https://user-images.githubusercontent.com/45194485/56979391-62432980-6b82-11e9-8d79-dde7c9d89b3b.jpg)

Вам нужно записать данные вашей точки доступа Wi-Fi и токен Blynk в память микроконтроллера.

Для записи SSID отправьте через терминал команду вида

**SSID=ВАШ_SSID**

Для просмотра записанного значения отправьте команду **SSID**

В терминал будет выведена строка с новым значением.

Аналогично установите значение пароля командой **PASS=ВАШ_ПАРОЛЬ_ТОЧКИ_ДОСТУПА**

Для просмотра записи используйте команду **PASS**

Для подключения к серверам Blynk надо записать ваш токен командой **TOKEN=ВАШ_ТОКЕН_Blynk**

Для просмотра записи используйте команду **PASS**

Перезагрузите плату с удержанием кнопки FLASH. На экране терминала появятся ваши новые значения

![17](https://user-images.githubusercontent.com/45194485/56153042-02635500-5fbe-11e9-8105-57af4ee26a59.jpg)

Теперь при включении плата NodeMcu будет автоматически подключаться к вашей домашней Wi-Fi сети и соединяться с сервером Blynk.


## Зарезервированные номера пинов arduino nano
(см. https://github.com/wisenheimer/Signaling-Blynk/blob/master/libraries/main_type/main_type.h):

#define	RING_PIN  2 // отслеживает вызовы с модема

#define	POWER_PIN 3 // отслеживает наличие питания

#define	DOOR_PIN  4 // датчик двери (геркон). Один конец на GND, второй на цифровой пин arduino.
К этому же пину подключён встроенный датчик температуры DS18B20.		      

#define	BOOT_PIN  5 // перезагрузка модема SIM800L

#define RADAR_PIN 6 // микроволновый датчик движения RCWL-0516

### Пины для подключения модуля RF24L01 по SPI интерфейсу

#define	CE_PIN    9

#define	CSN_PIN   10

#define	MO_PIN    11

#define	MI_PIN    12

#define	SCK_PIN   13

### Для ИК-приёмника

#define RECV_PIN  11

#	НАСТРОЙКА ДАТЧИКОВ

Инициализируем каждый датчик

Если у вас другой датчик (не из списка), опишите его аналогично, и добавьте в SENSORS_INIT

Номер параметра и значение (см. sensor.cpp)
1. пин ардуино
2. тип датчика. Типы датчиков перечислены в "sensor.h"
3. уникальное имя датчика (будет выводиться в отчётах).
4. уровень на цифровом пине датчика в спокойном режиме (LOW или  HIGHT)
5. время на подготовку датчика при старте в секундах,
   		когда к нему нельзя обращаться, чтобы не получить ложные данные.
   		Если не указать, то он будет равен 10 сек.
6. порог срабатывания аналогового датчика. По умолчанию равен 200.

Для беспроводных датчиков задаётся всего 3 параметра
Номер параметра и значение (см. sensor.cpp)
1. тип датчика IR_SENSOR или RF24_SENSOR
2. уникальное имя датчика. Будет выводиться в отчётах.
3. кодовое слово, передаваемое беспроводным датчиком при срабатывании

## Примеры описания датчиков:
  
Геркон. Для него зарезервирован 4 пин ардуины DOOR_PIN
  
**Sensor(DOOR_PIN, DIGITAL_SENSOR,"DOOR", HIGH,0)**
	
Датчик температуры DS18B20. Распаян на плате на пине DOOR_PIN
	
**Sensor(DOOR_PIN, DS18B20, "18B20", LOW, 10, 45)**
	
Датчик температуры и влажности DHT11, DHT21 или DHT22.

**Sensor(PIN, DHT11, "DHT")**

**Sensor(PIN, DHT21, "DHT")**

**Sensor(PIN, DHT22, "DHT")**

### Датчики с аналоговым выходом

Датчик температуры термистор. Заведён на плате на пин А7

**Sensor(A7, TERMISTOR, "TERM", LOW, 10, 45)**

Датчик газа MQ-2. Порог срабатывания задан равным 120.

**Sensor(A0, ANALOG_SENSOR, "GAS", LOW, 120)**

### Все датчики, где на выходе либо низкий, либо высокий логический уровень
	
Датчик движения RCWL-0516
	
**Sensor(PIN, DIGITAL_SENSOR,"RADAR",LOW)**
	
Датчик огня с проверкой на ложное срабатывание 10 сек.
	
**Sensor(PIN, CHECK_DIGITAL_SENSOR, "FIRE", HIGH)**	

### Беспроводные датчики:
	
Датчик с передающим ик-диодом
	
**Sensor(IR_SENSOR, "IR_0", IR_CODE)**

Датчик с передающим модулем RF24L01
	
**Sensor(RF24_SENSOR, "nRF_0", RF0_CODE)**

## Примеры сообщений от сигнализации
В ответном смс

номер звонившего (админа)
>AT+CMGS="+79xxxxxxxxx"


состояния флагов (1 - вкл, 0 - выкл).
>Svet ON.GUARD=1 EMAIL=0 TEL=1 CONNECT=0 SMS=1

где **Svet ON** - есть внешнее питание, **Svet OFF** - внешнее питание отсутствует.

**GUARD** - флаг охраны

**EMAIL** - флаг разрешения отправки сообщений по e-mail

**TEL** - флаг разрешения звонков

**CONNECT** - флаг удержания соединения по GPRS. Включение этого флага немного ускоряет отправку e-mail.

**SMS** - флаг разрешения отправки сообщений по sms.

>DOOR:0 FIRE:0 RADAR:0

названия и счётчик срабатываний всех датчиков.

Ответ оператора на USSD запрос:
>+CUSD: 0, "Balance:27,60r", 15

## Управление сигнализацией

**Примечание!** Все команды можно отправлять через терминал приложения Blynk.

### SMS с телефона Админа

Для переключения состояния пинов Ардуины отправьте смс вида
**set pin НОМЕР_ПИНА on/off**

Например, **set pin 14 on** и **set pin 14 off** задают пину 14 (А0) значения HIGH или LOW соответственно.
Поддерживаются пины от 5 до 19, где 14 соответствует А0, 15 соответствует А1 и т.д. 

**Внимание! Пины A6 и A7 не поддерживаются, т.к. они не работают как цифровые выходы.**

#### Отправка AT команд модему SIM800L.
Модем можно настраивать AT командами из его даташита. Для этого надо отправить в сигнализацию смс с AT командой с телефона Админа.

### DTMF команды

### 1#
GUARD_ON - постановка на охрану. Устанавливает флаг GUARD в 1.
### 2#
GUARD_OFF - снятие с охраны. Устанавливает флаг GUARD в 0.
### 3#
EMAIL_ON_OFF - включить/отключить GPRS/EMAIL. Меняет состояние флага EMAIL.
### 4#
SMS_ON_OFF - включить/отключить SMS. Меняет состояние флага SMS.
### 5#
TEL_ON_OFF - включить/отключить звонок при тревоге. Меняет состояние флага TEL.
### 6#
GET_INFO - сбор и отправка всех данных датчиков

Пример ответного смс:

>AT+CMGS="+79xxxxxxxxx"
>Svet ON.GUARD=1 EMAIL=0 TEL=1 CONNECT=0 SMS=1
>DOOR:0 FIRE:0 RADAR:0

### 7#
EMAIL_ADMIN_PHONE - отправляем на почту номер админа
### 8#
EMAIL_PHONE_BOOK - отправка на почту телефонной книги
### 9#
ADMIN_NUMBER_DEL - админ больше не админ
### 10#
SM_CLEAR - удалить все номера с симкарты
### 11#
MODEM_RESET - перезагрузка модема
### 12#
ESP_RESET - перезагрузка платы NodeMCU ESP8266
### 13#
BAT_CHARGE - показывает заряд батареи в виде строки
          +CBC: 0,100,4200
          где 100 - процент заряда
          4200 - напряжение на батарее в мВ.
### 14#
CONNECT_ON_OFF - Инвертирует флаг CONNECT_ALWAYS
### 15#
SENS_GET_NAMES - Возвращает имена датчиков
### 16#
SYNC_TIME - синхронизация времени модема SIM800L и часов на 7сигментном индикаторе

Кроме того, возможно выполнение любого USSD запроса, поддерживаемого оператором мобильной связи.
Например, запрос баланса *100#
Наберите 100# (знак * вводить не нужно).

В ответном смс

>AT+CMGS="+79xxxxxxxxx" - номер звонившего (админа)

>+CUSD: 0, "Balance:27,60r", 15 - ответ оператора

# Проблемы и способы их устранения
## SIM800L не отправляет e-mail
Возможные причины:

**1. Не определён оператор связи.**

При загрузке модем SIM800L определяет оператора свзязи и отправляет в порт его имя, которое можно посмотреть в терминале в режиме отладки. Например

>+COPS: 0,0,"Bee Line GSM"

>OK

Имёна известных операторов и пароли для GPRS соединения перечислены в файле https://github.com/wisenheimer/Signaling-Blynk/blob/master/libraries/modem/modem.cpp

>ADD_OP(0, "MTS",     "mts");

>ADD_OP(1, "MEGAFON", "gdata");

>ADD_OP(2, "MegaFon", "gdata");

>ADD_OP(3, "Tele2",   "");

>ADD_OP(4, "MOTIV",   "");

>ADD_OP(5, "Beeline", "beeline");

>ADD_OP(6, "Bee Line", "beeline");

В массиве ниже должно быть столько же операторов, сколько перечисленно выше.

>const OPERATORS op_base[] PROGMEM = {

>{op_0, user_0},

>{op_1, user_1},

>{op_2, user_2},

>{op_3, user_3},

>{op_4, user_4},

>{op_5, user_5},

>{op_6, user_6}

>};

Если вашего оператора нет в списке, или написание его имени отличается, необходимо добавить его в список/отредактировать имеющуюся запись.

После этого появится возможность отправлять e-mail по GPRS.

Сообщите мне имя своего оператора связи, чтобы я добавил его в базу.

**2. Проблема в операторе связи. Он рвёт соединение.**

- модем не дружит с этой конкретной симкой, попробовать с другой, желательно другого оператора

- не подходящий тариф

- не достаточно денег на счету.

**3. Проблема с почтовым ящиком.**

Создать другую почту на Яндекс, и попробовать с ней.
