export interface HoverAudioController {
  play(): void;
  stop(): void;
}

export function createHoverAudio(src: string, volume = 0.15): HoverAudioController {
  const audio = new Audio(src);
  audio.volume = volume;
  audio.preload = 'auto';

  return {
    play(): void {
      audio.currentTime = 0;
      void audio.play().catch(() => undefined);
    },
    stop(): void {
      audio.pause();
      audio.currentTime = 0;
    }
  };
}
