import RPI.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM) # BCM números depois do GPIO 

led = 24
buzzer = 8
relay = 20

GPIO.setup(led, GPIO.OUT)
GPIO.setup(buzzer, GPIO.OUT)
GPIO.setup(relay, GPIO.OUT)

button_press = True # Estado do botão 

if button_press:
    for contagem_regre in range(10, 0, -1):
       print(contagem_regre)
       GPIO.output(buzzer, GPIO.HIGH)
       print("Beep")
       time.sleep(1)
       
       #Opção para cancelar a ignição
       if(button_press == False):
           print("Botão cancelar pressionado, relé desligado.")
           GPIO.output(relay, GPIO.LOW)
           break
    
    GPIO.output(buzzer, GPIO.LOW)
    GPIO.output(led, GPIO.HIGH)
    GPIO.output(relay, GPIO.HIGH)
    print("\nRelé e led acionados.")

GPIO.cleanup() # Limpar/desconfigurar todos os pinos GPIO 

