;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Practica0) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
;Practica 0
; |x| es el cambio que hago para solucionar el error
"Expresiones Aritméticas"
"Ej 1"
(-(* 12 5)(* 7 6))
(/ (-(* 3 5)(* 7 4)) (+ 14 (/ 3 1)))
(+ (cos 0.8) 0.2 (* (sin 0.5) 3.5))

"Ej 2"
(/ 1 (sin (sqrt 3)))(/ 1 (sin (sqrt 3)))
(* (sqrt 2) (sin pi))
(+ 3 (sqrt (- 4)))
(* (sqrt 5) (sqrt (/ 3 (cos pi))))
; (/ (sqrt 5) (sin (* 3 0))) error: division by zero ->> (/ (sqrt 5) (sin (* 3 |1|)))
(/ (sqrt 5) (sin (* 3 1)))
;(/ (+ 3) (* 2 4)) error expects at least 2 arguments, but found only 1 ->> (/ |3| (* 2 4))
(/ 3 (* 2 4))
(* 1 2 3 4 5 6 7 8)
(/ 120 2 3 2 2 5)


"Strings"
"Ej 1"
(string-append "Hola" " mundo")
(string-append "Pro" "gra" "ma.")
(number->string 1357)
;(string-append "La respuesta es " (+ 21 21)) error: expects a string ->> (string-append "La respuesta es " (|number->string| (+ 21 21)))
(string-append "La respuesta es " (number->string (+ 21 21)))
(* (string-length "Hola") (string-length "Chau"))


"Valores de verdad"
"Ej 1"
(not #t)
(or #t #f)
(and #t #f)
(and #t (or #f (not #f)) (not #t))
(not (= 2 (* 1 3)))
(or (= 2 (* 1 3)) (< 4 (+ 3 2)))

"Ej 2"
(and (> pi 3) (= (+ 2 2) 5))

"Ej 3"
(> (cos 0) 0)
(= 14 (string-length "Hola, mundo"))
(and (< 3 pi) (> 4 pi))
(= (sqr 5) (sqrt 625))
(not (string=? "a" (string-ith "Ada Lovelace" 3)))


"Imagenes"
"Ej 1"
(circle 10 "solid" "red")
(rectangle 10 20 "solid" "blue")
(rectangle 20 12 "outline" "magenta")
(overlay (rectangle 20 20 "solid" "blue") (circle 7 "solid" "green"))
(empty-scene 100 100)
(place-image (circle 10 "solid" "blue") 40 80 (empty-scene 100 100))
(+ (image-width (circle 10 "solid" "red")) (image-height (rectangle 10 20 "solid" "blue")))


"Funciones y Constantes"
(define P "Neptuno")
(define 1TRES 3)
(define CINCO (+ 1 (* 2 2)))
(define VERDADERO #true)
(define PUNTOROJO (circle 3 "solid" "red"))

"Ej 1"
(define (sucesor x) (+ x 1))
(define (doble x) (* x 2))
(define (triple x) (* x 3))
(define (x-menor-2y? x y) (< x (doble y)))
(define (cuad-azul x) (square x "solid" "blue"))

(cuad-azul (doble 10))
(and (x-menor-2y? 2 3) (x-menor-2y? 3 4))
(= (sucesor 1) (doble 1))

"Ej 2"
;Resuelvo haciendo el modulo de un vector en el plano (x,y)
(define (dist-origen x y) (sqrt (+ (sqr x) (sqr y))))
(dist-origen 4 3)

"Ej 3"
;Resuelvo haciendo vector por dos puntos y llevandolos al origen
(define (dist-puntos a b x y) (dist-origen (- x a) (- y b)))
(dist-puntos 1 2 4 3)

"Ej 4"
(define (vol-cubo x) (triple x))
(vol-cubo 5)

"Ej 5"
(define (area-cubo x) (doble x))
(area-cubo 5)

"Ej 6"
(define (metro-pie x) (* x 3.28084))
(metro-pie 1.8288)

"Ej 7"
(define (cel-far x) (+ (* x (/ 9 5)) 32))
(cel-far 0)

"Ej 8"
(define (posible? x y z) (and (< x (+ y z)) (< y (+ x z)) (< z (+ x y))))
(posible? 1 1 1)
(posible? 1 2 5)

"Ej 9"
; Una terna pitagórica es un conjunto ordenado de tres números enteros positivos a, b, c, y son solución de la ecuación a^2 + b^2 = ^c^2
(define (pitagorica? a b c) (= (+ (sqr a) (sqr b)) (sqr c)))
(pitagorica? 4 3 5)
(pitagorica? 2 1 1)

"Ej 10"
(define (suma-log x y) (+ (string-length x) (string-length y)))
(suma-log "hola" " mundo")

"Ej 11"
(define (comienzaA? x) (string=? "A" (string-ith x 0)))
(comienzaA? "Alga")
(comienzaA? "alga")

"Ej 12"
(define (poner- xs i) (string-append (substring xs 0 i) "-" (substring xs i (string-length xs))))
(poner- "HolaMundo" 4)

