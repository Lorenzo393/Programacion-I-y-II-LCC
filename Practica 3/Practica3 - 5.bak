;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica3 - Ej 4|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PROGRAMAS INTERACTIVOS
;Ej 4
(define CIRCULO (circle 20 "solid" "red"))
(define ESCENA (empty-scene 300 300))
(define DELTA 10)

(define (pantalla2 y)
  (place-image CIRCULO
               150
               y
               ESCENA))

(define (mover y k)
  (cond [(and (string=? "up" k) (>= y 30)) (- y DELTA)]
        [(and (string=? "down" k) (<= y 270)) (+ y DELTA)]
        [(string=? "r" k) 150]
        [else y]))
; No se como es la barra espaciadora en racket
(define (mouse-handler y x y2 event)
  (cond [(string=? event "button-down") y2]
        [else y]))

(big-bang (/(image-height ESCENA) 2)
  [to-draw pantalla2]
  [on-key mover]
  [on-mouse mouse-handler])