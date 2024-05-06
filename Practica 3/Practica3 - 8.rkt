;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica3 - 8|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PROGRAMAS INTERACTIVOS
;Ej 8

(define FONDO (empty-scene 300 300))
(define STAR (star 20 "solid" "red"))

(define (pantalla f)
  (place-image f
               150 150
               FONDO))

(define (mouse f x y event)
  (cond [(string=? event "button-down") (place-image STAR
                                                     x y
                                                     f)]
        [else f]))

(define (teclado f k)
  (cond [(string=? "\b" k) FONDO]
        [else f]))


(big-bang FONDO
  [to-draw pantalla]
  [on-mouse mouse]
  [on-key teclado])