<script setup>
import { computed } from 'vue'
import { useDesktopStore } from '../../store/desktop'
const DesktopStore = useDesktopStore()

const displayname = computed(() => {
  return DesktopStore.getSelectedAppName() || '任务栏'
})
</script>

<template>
  <div class="taskbar">{{ displayname }}</div>
</template>

<style scoped>
.taskbar {
  position: fixed;
  bottom: 0;
  left: 0;
  width: 100vw;
  height: 5vh;
  background: rgba(0, 0, 0, 0.5);
  color: white;
  line-height: 5vh;
  text-align: center;
}
</style>
