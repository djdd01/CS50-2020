WINDOW_WIDTH = 1920
WINDOW_HEIGHT = 1080

VIRTUAL_WIDTH = 1920
VIRTUAL_HEIGHT = 1080

PADDLE_SPEED = 600
class = require'class'
push = require 'push'
require 'Paddle'
require 'Ball'

function love.load()
    math.randomseed(os.time())
    love.window.setTitle('Pong')

    sounds = {
        ['paddle_hit'] = love.audio.newSource('paddlehit.wav', 'static'),
        ['wall_hit'] = love.audio.newSource('wall_hit.wav', 'static'),
        ['score'] = love.audio.newSource('Explosion13.wav', 'static'),
        ['victory'] = love.audio.newSource('Victory.wav', 'static')
    }

    love.graphics.setDefaultFilter('nearest', 'nearest')
    smallfont = love.graphics.newFont('Caferesto.ttf', 48)
    scorefont = love.graphics.newFont('Caferesto.ttf', 64)
    smallerfont = love.graphics.newFont('Caferesto.ttf', 32)
    p1score = 0
    p2score = 0
    paddle1 = Paddle(250, VIRTUAL_HEIGHT / 2 - 48, 16, 64)
    paddle2 = Paddle(1670, VIRTUAL_HEIGHT / 2 - 32, 16, 64)
    ball = Ball(VIRTUAL_WIDTH / 2 - 4, VIRTUAL_HEIGHT / 2 - 4, 8, 2000)
    servingplayer = math.random(2)
    winningplayer = 0
    gamestate = 'start'

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT,
                     {fullscreen = false, vsync = true, resizable = false})
end

function love.resize(w, h)
    push:resize(w, h)
end

function love.update(dt)
    if ball:collides(paddle1) or ball:collides(paddle2) then
        sounds['paddle_hit']:play()
        ball.dx = -ball.dx
    end
    if ball.y <= 110 or ball.y >= 950 then
        sounds['wall_hit']:play()
        ball.dy = -ball.dy
    end
    paddle1:update(dt)
    paddle2:update(dt)

    if love.keyboard.isDown('up') then
        paddle2.dy = -PADDLE_SPEED
    elseif love.keyboard.isDown('down') then
        paddle2.dy = PADDLE_SPEED
    else
        paddle2.dy = 0
    end

    if love.keyboard.isDown('w') then
        paddle1.dy = -PADDLE_SPEED
    elseif love.keyboard.isDown('s') then
        paddle1.dy = PADDLE_SPEED
    else
        paddle1.dy = 0
    end

    if gamestate == 'play !' then
        ball:update(dt)
        paddle2.y = ball.y - paddle2.height / 2 + ball.dy * dt
        paddle2.dy = ball.dx
        if ball.x - ball.radius / 2 <= 150 then
            sounds['score']:play()
            p2score = p2score + 1
            servingplayer = 1
            ball:reset()
            ball.dx = 400
            if p2score == 10 then
                sounds['victory']:play()
                gamestate = 'victory'
                winningplayer = 2
                ball:reset()
            else
                gamestate = 'serve'
            end
        elseif ball.x + ball.radius / 2 >= 1750 then
            sounds['score']:play()
            p1score = p1score + 1
            servingplayer = 2
            ball:reset()
            ball.dx = -400
            if p1score == 10 then
                sounds['victory']:play()
                gamestate = 'victory'
                winningplayer = 1
                ball:reset()
            else
                gamestate = 'serve'
            end
        end
    end

end

function love.keypressed(key)
    if key == 'escape' then love.event.quit() end

    if key == 'return' or key == 'enter' then
        if gamestate == 'serve' or gamestate == 'start' then
            gamestate = 'play !'
        elseif gamestate == 'play !' then
            gamestate = 'start'
        elseif gamestate == 'victory' then
            gamestate = 'start'
            p1score = 0
            p2score = 0
        end
    end
    if key == 'p' then
        if gamestate == 'play !' then
            gamestate = 'start'
        else
            gamestate = 'play !'
        end
    end
end

function love.draw()
    push:apply('start')

    love.graphics.clear(40 / 255, 45 / 255, 52 / 255, 255 / 255)
    paddle1:render()
    paddle2:render()
    ball:render()
    love.graphics.setFont(smallfont)
    if gamestate == 'start' then
        love.graphics.printf("Hello Pong!", 0, 200, VIRTUAL_WIDTH, 'center')
        love.graphics.setFont(smallerfont)
        love.graphics.print(gamestate, VIRTUAL_WIDTH / 2 - 40, VIRTUAL_HEIGHT / 4)
        love.graphics.printf("Press Enter to Play", 0 , 150, VIRTUAL_WIDTH, 'center')
    elseif gamestate == 'serve' then
        love.graphics.setFont(smallfont)
        love.graphics.printf('player' .. tostring(servingplayer) .. "'s serve", 0, 200, VIRTUAL_WIDTH, 'center')
        love.graphics.setFont(smallerfont)
        love.graphics.printf("Press Enter to Serve", 0 , 150, VIRTUAL_WIDTH, 'center')
        love.graphics.print(gamestate, VIRTUAL_WIDTH / 2 - 40, VIRTUAL_HEIGHT / 4)
    elseif gamestate == 'play !' then
        love.graphics.setFont(smallfont)
        love.graphics.printf("Hello Pong!", 0, 200, VIRTUAL_WIDTH, 'center')
        love.graphics.setFont(smallerfont)
        love.graphics.print(gamestate, VIRTUAL_WIDTH / 2 - 40, VIRTUAL_HEIGHT / 4)
    elseif gamestate == 'victory' then
        love.graphics.setFont(scorefont)
        love.graphics.printf('Player' .. tostring(winningplayer) .. 'wins!', 0, 200, VIRTUAL_WIDTH, 'center')
        love.graphics.setFont(smallerfont)
        love.graphics.printf("Press Enter to Restart", 0 , 150, VIRTUAL_WIDTH, 'center')
    end
    love.graphics.setFont(scorefont)
    love.graphics.print(p1score, VIRTUAL_WIDTH / 2 - 128, VIRTUAL_HEIGHT / 3)
    love.graphics.print(p2score, VIRTUAL_WIDTH / 2 + 96, VIRTUAL_HEIGHT / 3)

    displayFPS()

    push:apply('end')
end

function displayFPS()
    love.graphics.setFont(smallerfont)
    love.graphics.setColor(0,1,0,1 )
    love.graphics.print('FPS: ' .. tostring(love.timer.getFPS()), 300, 200)
    love.graphics.setColor(1,1,1,1)
end