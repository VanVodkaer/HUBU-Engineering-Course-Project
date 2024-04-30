<script setup>
import DesktopIcon from './DesktopIcon.vue'
import { useDesktopStore } from '@renderer/store/desktop'
const DesktopStore = useDesktopStore()

DesktopStore.initApps()
</script>

<template>
  <div class="desktop-main">
    <DesktopIcon v-for="item in DesktopStore.apps" :key="item.id" :app="item"></DesktopIcon>
  </div>
</template>

<style scoped>
.desktop-main {
  background-color: #7cffeb;
  background-image: url(@renderer/assets/bg.jpg);
  background-size: cover;
  background-repeat: no-repeat;
  background-position: center;
  background-attachment: fixed;
  width: 100vw;
  height: 95vh;
}
</style>
