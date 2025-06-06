;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Practica1-1) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require racket/base)
;Practica 1 parte 1

;REPASO DE FUNCIONES
;Ej 1 y 2
(define (AAC x)
  (cond [(< (image-width x) (image-height x)) "Angosta"]
        [(> (image-width x) (image-height x)) "Ancha"]
        [else "Cuadrada"]))
;Ej 3 y 4
(define (ang x y z)
  (cond [(not (= (+ x y z) 180)) "No es triangulo"]
        [(= x y z) "Equilatero"]
        [(= x y) "Isosceles"]
        [(= x z) "Isosceles"]
        [(= y z) "Isosceles"]
        [else "Escaleno"]))
;Ej 5 y 6
(define PC 60)
(define PL 8)

(define (precio c l)
  (cond [(>= (+ c l) 10) (+ (* l PL 0.82) (* c PC 0.82))]
        [(and (>= l 5) (>= c 4)) (+ (* l PL 0.85) (* c PC 0.90))]
        [(>= l 5) (+ (* l PL 0.85) (* c PC))]
        [(>= c 4) (+ (* l PL) (* c PC 0.90))]
        [else (+ (* l PL) (* c PC))]))
;Ej 7
(define (pitagorica? a b c)
  (if (= (+ (sqr a) (sqr b)) (sqr c)) #true #false))

(define (pitagoricax? a b c)
  (cond [(= (+ (sqr a) (sqr b)) (sqr c)) #true]
        [else #false]))
;Ej 8
(define (pitagoricastr? a b c)
  (if (= (+ (sqr a) (sqr b)) (sqr c)) (string-append "Los numeros " (number->string a)
      ", "(number->string b) " y " (number->string c) " forman una terna pitagorica")
      (string-append "Los numeros " (number->string a)
      ", "(number->string b) " y " (number->string c) " no forman una terna pitagorica")))
;Ej 9
; Tengo que saber como comprobar si un numero es entero


;BANDERAS
(define MARCOBANDERA (empty-scene 90 60))

;Ej a
(define PERU (place-image (rectangle 30 60 "solid" "red")
                          15 30
                          (place-image (rectangle 30 60 "solid" "red")
                                       75 30
                                       MARCOBANDERA)))
;Ej b
(define ITALIA (place-image (rectangle 30 60 "solid" "green")
                          15 30
                          (place-image (rectangle 30 60 "solid" "red")
                                       75 30
                                       MARCOBANDERA)))
;Ej c
(define (rayadav c1 c2 c3)
  (place-image (rectangle 30 60 "solid" c1)
                          15 30
                          (place-image (rectangle 30 60 "solid" c2)
                                       45 30
                                       (place-image (rectangle 30 60 "solid" c3)
                                                    75 30
                                                    MARCOBANDERA))))
;Ej d
(define ALEMANIA (place-image (rectangle 90 20 "solid" "black")
               45 10
               (place-image (rectangle 90 20 "solid" "red")
               45 30
               (place-image (rectangle 90 20 "solid" "yellow")
               45 50
               MARCOBANDERA))))
;Ej e
(define HOLANDA (place-image (rectangle 90 20 "solid" "red")
               45 10
               (place-image (rectangle 90 20 "solid" "white")
               45 30
               (place-image (rectangle 90 20 "solid" "blue")
               45 50
               MARCOBANDERA))))
;Ej f
(define (rayadah c1 c2 c3)
  (place-image (rectangle 90 20 "solid" c1)
               45 10
               (place-image (rectangle 90 20 "solid" c2)
               45 30
               (place-image (rectangle 90 20 "solid" c3)
               45 50
               MARCOBANDERA))))
;Ej g (tengo que hacerlo con case no con if)
(define (bandenaitor c1 c2 c3 o)
  (cond [(string=? "vertical" o) (rayadav c1 c2 c3)]
        [(string=? "horizontal" o) (rayadah c1 c2 c3)]))
;Ej h
(define FRANCIA (bandenaitor "blue" "white" "red" "vertical"))
FRANCIA
;Ej i
(place-image (rotate 30 (triangle 60 "solid" "green"))
             25 30
             (bandenaitor "red" "white" "black" "horizontal"))

(place-image (circle 8 "solid" "yellow")
             45 30
             (bandenaitor "blue" "white" "blue" "horizontal"))

(place-image (star 10 "solid" "yellow")
             45 30
             (bandenaitor "green" "red" "yellow" "vertical"))
;Ej j
(place-image (circle 12.5 "solid" "blue")
             45 30
             (place-image (rotate 30(triangle 40 "solid" "yellow"))
                          62 30
                          (place-image (rotate -30 (triangle 40 "solid" "yellow"))
                          28 30
                          (bandenaitor "green" "green" "green" "horizontal"))))
;Ej k
(define (bandenaitorx2 c1 c2 c3 o)
  (cond [(string=? "vertical" o) (scale 2 (rayadav c1 c2 c3))]
        [(string=? "horizontal" o) (scale 2 (rayadah c1 c2 c3))]))

(define (bandenaitor-ultra x c1 c2 c3 o)
  (cond [(string=? "vertical" o) (scale x (rayadav c1 c2 c3))]
        [(string=? "horizontal" o) (scale x (rayadah c1 c2 c3))]))