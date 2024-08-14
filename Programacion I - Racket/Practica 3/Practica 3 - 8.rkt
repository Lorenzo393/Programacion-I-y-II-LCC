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

(define (pantalla f)
  (place-image f
               150 150
               FONDO))

(define (limite f x y)
  (if (or (> (+ x (image-width (size x))) (+ (image-width FONDO) 50))
          (< (- x (image-width (size x))) 0)
          (> (+ y (image-height (size x))) (+ (image-height FONDO) 50))
          (< (- y (image-height (size x))) 0))
      f
      (place-image (size x)
                   x y
                   f)))

(define (size x)
  (cond [(>= x 150) (star (/ x 4) "solid" "red")]
        [(>= x 50) (star (/ x 4) "solid" "blue")]
        [else (star (/ x 4) "solid" "yellow")]))


(define (mouse f x y event)
  (cond [(string=? event "button-down") (limite f x y)]
        [else f]))

(define (teclado f k)
  (cond [(string=? "\b" k) FONDO]
        [else f]))

(big-bang FONDO
  [to-draw pantalla]
  [on-mouse mouse]
  [on-key teclado])