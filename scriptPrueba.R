#guia de comandos
?dbinom

#instalar un paquete
install.packages("ggplot2")

#cargar un paquete
library(gplot2)

#asignacion de valores 
x <- 2

x^2-3

y <- x^2-3

#imprimir por pantalla
printf(y)
y

#estructura y manipulacion de hojas de datos

#cargar una hoja de datos

data(mtcars)

#imprimir por pantalla mtcars -> salida en consola

mtcars

#ver mtcars como hoja de calculo o matriz -> salida en scripts

View(mtcars)

# peso (sexta variable)
# del Hornet Sportabout (quinto vehículo)

mtcars[5,6]

#Todas las carc. del Hornet Sportabout

mtcars[5,]

#peso de todos los vehículos 

mtcars[,6]

#extraer variable

mtcars$wt

#almacenar valores en un vector

pesos <- mtcars$wt

#media

mean(pesos)

#desviacion tipica

sd(pesos)

#importar datos

#importar archivo temperaturas.csv

temps <- read.csv("temperaturas.csv")

#leer temperaturas.csv

View(temps)

#vector temperaturas maximas

maximas <- temps$Tmax

#media de las maximas

mean(maximas)

#temp maxima de las maximas

max(maximas)

#instalar librerias

library(ggplot2)
library(scales)

#convertir fechas

temps$Fecha <- as.Date(temps$Fecha, format = "%d/%m/%Y")
View(temps)

#graficos

ggplot(data = temps, aes(x = Fecha)) +
  geom_line(aes(y = Tmax), colour="red") +
  geom_line(aes(y = Tmin), colour="blue") +
  scale_x_date(
    expand=c(0,0),
    breaks = date_breaks("1 day"),
    labels = date_format("%d")
  ) +
  scale_y_continuous(breaks = seq(-5,35,5)) +
  ggtitle ("Temperaturas máximas y mínimas en abril del 2018") +
  xlab("Día") +
  ylab ("Temperatura ( oC )")
  
