# Prosjektplan

## Hva planen gjelder

Denne planen viser hvordan jeg skal bygge prosjektet **Embedded Linux-sensornode** fra start til slutt.

Sist kontrollert: 17. august 2026, mot kildekoden i prosjektet.

## Status

- [x] Ferdig og kontrollert
- [ ] Planlagt / ikke funnet i prosjektet ennå
- [~] Delvis ferdig

---

## Fase 1 – Første C++-versjon på Mac

### Mål

Lage et enkelt C++-program som fungerer uten Raspberry Pi-maskinvare.

### Oppgaver

- [x] Opprette prosjektmappen
- [ ] Opprette `README.md`
- [x] Opprette `CMakeLists.txt`
- [x] Opprette `main.cpp`
- [x] Generere en simulert temperatur
- [x] Bygge programmet med CMake


---

## Fase 2 – Forbedre FakeSensor

### Mål

Få den simulerte temperaturen til å oppføre seg mer som en ekte sensor.

### Oppgaver

- [x] Kontrollere at starttemperaturen er mellom 10 og 20 grader
- [x] Kontrollere at sensoren husker den forrige temperaturen
- [x] Kontrollere at temperaturen endrer seg gradvis
- [x] Flytte `FakeSensor`-koden til separate filer
- [x] Kontrollere at programmet kjører kontinuerlig
- [x] Kontrollere at Ctrl+C stopper programmet på en ryddig måte
- [x] Legge til et konfigurerbart måleintervall

---

## Fase 3 – Lagre og organisere målinger

### Mål

- [x] Gjøre utskriften lettere å forstå og lagre målingene.

### Oppgaver

- [x] Legge til tidsstempler
- [x] Lagre målinger i en CSV-fil
- [x] Håndtere enkle filfeil
- [x] Forbedre meldingene i terminalen
- [x] Begrense CSV-filen til de 10 nyeste målingene
- [x] Legge til en enkel konfigurasjonsfil
- [x] La konfigurasjonen styre måleintervall, CSV-filnavn og maksimalt antall målinger
- [x] Legge til en egen Logger-modul med NORMAL, WARNING og ERROR

---

## Fase 4 – Bedre kodestruktur og tester

### Mål

Klargjøre programmet for både simulerte og ekte sensorer.

### Oppgaver

- [ ] Opprette et `ISensor`-grensesnitt
- [ ] La `FakeSensor` bruke `ISensor`
- [x] Legge til grunnleggende validering av temperaturverdier
- [x] Avvise NaN, uendelige og verdier utenfor konfigurerte temperaturgrenser
- [ ] Legge til GoogleTest
- [~] Legge til versjonsinformasjon i programmet (versjonen finnes bare i CMake)
- [ ] Legge til GitHub Actions
- [ ] Legge til kontroller med sanitizers

---

## Fase 5 – Raspberry Pi og ekte sensor

### Mål

Flytte prosjektet fra Mac til Raspberry Pi og bruke en ekte I2C-sensor.

### Oppgaver

- [ ] Installere Raspberry Pi OS
- [ ] Aktivere I2C
- [ ] Koble til en AHT21- eller BMP280-sensor
- [ ] Kontrollere sensoren med `i2cdetect`
- [ ] Opprette `I2CSensor`
- [ ] Lese data fra `/dev/i2c-1`
- [ ] Konvertere rådata til temperatur
- [ ] Velge simulert eller ekte sensor i konfigurasjonsfilen
- [ ] Legge til dokumentasjon for koblingene på Raspberry Pi

---

## Fase 6 – Linux-tjeneste og overvåking

### Mål

Få programmet til å starte automatisk og sende målingene til et overvåkingssystem.

### Oppgaver

- [ ] Opprette en `systemd`-tjeneste
- [ ] Starte programmet automatisk ved oppstart
- [ ] Starte programmet på nytt hvis det krasjer
- [ ] Sende logger til `journald`
- [ ] Publisere målinger med MQTT
- [ ] Lagre målingene i InfluxDB
- [ ] Vise målingene i Grafana

---

## Fase 7 – Yocto-image

### Mål

Bygge et eget Embedded Linux-image for Raspberry Pi.

### Oppgaver

- [ ] Sette opp Yocto
- [ ] Legge til Raspberry Pi-laget
- [ ] Opprette `meta-sensor-node`
- [ ] Opprette en BitBake-recipe
- [ ] Installere daemonen, tjenesten og konfigurasjonen
- [ ] Bygge imaget
- [ ] Starte Raspberry Pi med imaget

---

## Fase 8 – Trådløs oppdatering med Mender

### Mål

Oppdatere enheten via nettverket uten å skrive SD-kortet på nytt manuelt.

### Oppgaver

- [ ] Legge Mender til i Yocto-imaget
- [ ] Bygge versjon 1.0.0
- [ ] Bygge versjon 1.1.0
- [ ] Sende oppdateringen med Mender
- [ ] Kontrollere at den nye versjonen kjører
- [ ] Dokumentere oppdateringen
- [ ] Teste tilbakerulling hvis tiden tillater det

---

## Fase 9 – Sluttdokumentasjon

### Mål

Gjøre prosjektet enkelt for andre å forstå.

### Oppgaver

- [ ] Ferdigstille hovedfilen `README.md`
- [ ] Legge til et arkitekturdiagram
- [ ] Forklare arkitekturen og dataflyten
- [x] Legge til denne prosjektplanen
- [ ] Legge til dokumentasjon for sensorkoblingene
- [ ] Legge til instruksjoner for bygging og testing
- [ ] Legge til skjermbilder fra Grafana
- [ ] Legge til skjermbilder fra Mender
- [ ] Måle CPU- og minnebruk
- [ ] Spille inn en kort demonstrasjonsvideo
- [ ] Skrive en avsluttende refleksjon

---

Denne planen kan endres underveis hvis jeg finner en bedre eller enklere måte å løse noe på.
