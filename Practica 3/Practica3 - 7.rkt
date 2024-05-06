;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica3 - 7|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PROGRAMAS INTERACTIVOS
;Ej 7

(define AUTO (circle 20 "solid" "red"))
(define FONDO (empty-scene 300 50))
(define INICIAL 20)
;Buscar imagen de auto

(define (pantalla x)
  (place-image AUTO
               x 25
               FONDO))

(define (movimiento x)
  (cond [(>= x 280) x]
        [else (+ x 3)]))

(define (teclado x t)
  (cond [(string=? " " t) INICIAL]
        [(string=? "right" t) (+ x 20)]
        [(string=? "left" t) (- x 20)]
        [else x]))

(define (mouse n x y event)
  (cond [(string=? event "button-down") x]
        [else n]))

(big-bang INICIAL
  [to-draw pantalla]
  [on-tick movimiento 1]
  [on-key teclado]
  [on-mouse mouse])