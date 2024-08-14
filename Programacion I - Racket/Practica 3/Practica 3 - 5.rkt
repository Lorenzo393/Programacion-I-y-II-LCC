;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica3 - 5|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PROGRAMAS INTERACTIVOS
;Ej 5
(define INICIAL "yellow")
(define ANCHO 300)
(define ALTO 300)

(define FONDO (empty-scene ALTO ANCHO))

(define (pantalla c)
  (place-image (circle 20 "solid" c)
               (/ ANCHO 2) (/ ALTO 2)
               FONDO))

(define (cambio-color c)
  (cond [(string=? c "yellow" ) "red"]
        [(string=? c "red" ) "green"]
        [(string=? c "green" ) "blue"]
        [(string=? c "blue" ) "yellow"]))


(big-bang INICIAL
  [to-draw pantalla]
  [on-tick cambio-color 1])