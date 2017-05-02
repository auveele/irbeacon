# IRBeacon - Baliza IR

Baliza de IR para controlar varios dispositivos de la misma habitación.
Proyecto todavía en desarrollo.

## Características
- Control de Chuwi iLife X5
- Control de la Tv Bas Marca TD Systems con comunicación IR basada en el protocolo RC5

## Dependencias
- Librería IRRemote de Arduino. https://github.com/z3t0/Arduino-IRremote
- Librería IRRemoteESP8266. https://github.com/markszabo/IRremoteESP8266

## TODO List
- [ ] Hacer todo no bloqueante. Sin delays.
- [x] Separar MQTT en otro archivo.
- [ ] Reparar movida String en la función callback.
- [ ] Esquema del circuito.
