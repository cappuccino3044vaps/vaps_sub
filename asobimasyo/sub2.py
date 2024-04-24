import pygame
import sys
import random
import time

def Game_main():
    # 初期化
    pygame.init()

    #初期時刻
    start_time=time.time()
    # 画面の設定
    screen_size=[600,800]
    screen = pygame.display.set_mode(screen_size)
    pygame.display.set_caption("弾幕ゲーム")

    # 色
    WHITE = (255, 255, 255)
    RED = (255,0,0)

    # プレイヤー
    player_image = pygame.image.load("Player.png").convert_alpha()
    player_image.fill(WHITE)
    player_rect = player_image.get_rect(center=(screen_size[0]/2, screen_size[1]-100))
    player_speed = 1

    # Enemy
    enemy_image = pygame.Surface((10,10))
    enemy_image.fill(RED)
    enemy_rect = enemy_image.get_rect(center=(pop_position(screen_size),10))
    enemy_speed = 0.5  # 敵の速度を半分に
    enemy_spawn_time = 1  # 敵の出現時間間隔

    # メインループ
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        
        # 敵の出現
        current_time = time.time()
        if current_time - start_time > enemy_spawn_time:
            enemy_rect = enemy_image.get_rect(center=(pop_position(screen_size), 10))
            start_time = current_time

        # 敵の移動
        if enemy_rect.y > screen_size[1]-1:
            enemy_rect.y = 0
        else:
            enemy_rect.y += enemy_speed

        
        # プレイヤーの操作
        keys = pygame.key.get_pressed()

        if keys[pygame.K_LEFT]:
            player_rect.x -= player_speed
            if player_rect.x < 0:
                player_rect.x += 1

        if keys[pygame.K_RIGHT]:
            player_rect.x += player_speed
            if player_rect.x > screen_size[0]-10:
                player_rect.x -= 1

        if keys[pygame.K_UP]:  # 上矢印キーで上に移動
            player_rect.y -= player_speed
            if player_rect.y < 0:
                player_rect.y += 1

        if keys[pygame.K_DOWN]:  # 下矢印キーで下に移動
            player_rect.y += player_speed
            if player_rect.y > screen_size[1] - 10:
                player_rect.y -= 1

        # 画面描画
        screen.fill((0, 0, 0))
        screen.blit(player_image, player_rect)
        screen.blit(enemy_image, enemy_rect)
        
        pygame.display.flip()

def pop_position(screen_size):
    x = random.randint(0, screen_size[0])
    return x
