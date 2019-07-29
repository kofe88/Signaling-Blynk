#ifndef SETTINGS_H
#define SETTINGS_H

/*
 * В этом файле настройки осуществляются дефайнами
 * Для выбора настроки в дефайне указывают 1.
 * Для запрета указывают 0.
 */

//------------------------------------------------------------------------------
// Вывод отладочных сообщений в Serial
// В рабочем режиме вывод должен быть запрещён
#define DEBUG_MODE 0
//------------------------------------------------------------------------------
// скорость последовательного порта Serial
#define SERIAL_RATE	115200
// СМС на кирилице. Длина СМС не более 70 символов. Иначе латиницей до 160 символов.
#define PDU_ENABLE  1 // Включаем PDU-режим для отправки СМС на кирилице, иначе латиница
#define SMS_FORWARD 0 // пересылаем входящие смс админу
//------------------------------------------------------------------------------
// Коды для беспроводных датчиков. Можно менять на свои.
// Эти коды передатчик будет отправлять приёмнику

// Для датчиков c nRF24.
#define RF0_CODE 0xAA
#define RF1_CODE 0xBB
#define RF2_CODE 0xCC
#define RF3_CODE 0xDD
#define RF4_CODE 0xEE
#define RF5_CODE 0xFF

// Для ИК - датчика
#define IR_CODE	0x41038C7
#define IR_CODE_BIT_SIZE 32 // размер кода в битах

// Используем watchdog (только с подходящим загрузчиком или без загрузчика в плате ардуино)
#define WTD_ENABLE 0

#include "main_type.h"

//****************************************************
// Выбор способа получения отчётов (или GPRS, или SMS).
// Если разрешить оба флага SET_FLAG_ONE(EMAIL_ENABLE) и SET_FLAG_ONE(SMS_ENABLE),
// приоритет отдаётся GPRS. Если не удастся установить GPRS соединение, сообщения
// будут отправлены по SMS. Оба флага можно установить DTMF командами
// GPRS_ON_OFF и SMS_ON_OFF (см https://github.com/wisenheimer/Signaling-Blynk/blob/master/README.md).
// Отключить любой флаг можно, записав SET_FLAG_ZERO
//****************************************************
#define OTCHET_INIT	SET_FLAG_ONE(EMAIL_ENABLE);SET_FLAG_ONE(SMS_ENABLE);
//****************************************************
//////////////////////////////////////////////////////////
/// Изменить параметры под себя
//////////////////////////////////////////////////////////
// Отправка почты
#define SMTP_SERVER					F("\"smtp-devices.yandex.com\",25") // почтовый сервер яндекс и порт
#define SMTP_USER_NAME_AND_PASSWORD	F("\"login\",\"password\"") // Логин и пароль от почты
#define SENDER_ADDRESS_AND_NAME		F("\"login@yandex.com\",\"SIM800L\"")
#define RCPT_ADDRESS_AND_NAME		F("\"login@mail.ru\",\"Alex\"") // Адрес и имя получателя
//#	define RCPT_CC_ADDRESS_AND_NAME		F("\"login@yandex.ru\",\"Ivan\"") // Адрес и имя получателя (копия)
//#	define RCPT_BB_ADDRESS_AND_NAME		F("\"login2@yandex.ru\",\"Ivan\"") // Адрес и имя получателя (вторая копия)

// Разрешаем спящий режим для экономии батареи при отключении электричества
#define SLEEP_MODE_ENABLE 0
//////////////////////////////////////////////////////////
// Подключаемые библиотеки.
// Для отключения библиотеки и экономии памяти 1 меняем на 0 и наоборот
//////////////////////////////////////////////////////////
#define BEEP_ENABLE   1 // пищалка, не работает совместно с IR_ENABLE
#define DHT_ENABLE    0 // библиотека датчиков DHT11, DHT21 и DHT22
#define TERM_ENABLE   0 // библиотека для термистора
#define DS18_ENABLE   1 // библиотека для датчика DS18B20
#define TM1637_ENABLE 0 // семисигментный индикатор для часов
// Эти две библиотеки можно включать только для Signalka.ino
//----------------------------------------------------------
#define IR_ENABLE 0 // библиотека для ик приёмника
#define RF_ENABLE 0 // библиотека для Wi-Fi модуля RF24L01
//----------------------------------------------------------
// Часы на 7сигментном индикаторе TM1637
//----------------------------------------------------------
// Пины
#define CLK 7         
#define DIO 8
// яркость, от 0 до 7
#define brightness 2

#endif // SETTINGS_H
