<script setup>
import { computed, ref } from 'vue'
import { useDesktopStore } from '@renderer/store/desktop'
const DesktopStore = useDesktopStore()

const props = defineProps({
  app: Object
})
const srcValue = computed(() => {
  return DesktopStore.resUrl + props.app.iconSrc
})

const nameValue = ref(props.app.name)
const commandValue = ref(props.app.command)

const element = ref(null)
function handleClick() {
  DesktopStore.selectOne(props.app.id)
}

function handleDblClick() {
  // element.value.classList.remove('selected')
  DesktopStore.clearAllSelected()
  DesktopStore.openApp(commandValue.value)
}
</script>

<template>
  <div
    ref="element"
    class="desktop-icon"
    :class="{ selected: props.app.id === DesktopStore.selected }"
    @click="handleClick()"
    @dblclick="handleDblClick()"
  >
    <img :src="srcValue" :alt="nameValue" />
    <span>{{ props.app.name }}</span>
  </div>
</template>

<style scoped>
.desktop-icon {
  width: 80px;
  text-align: center;
  margin: 20px;
  display: inline-block;
  position: relative;
  cursor: pointer;
}
.desktop-icon img {
  width: 64px;
  height: 64px;
}
.desktop-icon span {
  display: block;
  text-align: center;
  color: white;
  text-shadow: 0px 0px 5px rgba(0, 0, 0, 0.7);
  overflow: hidden;
  white-space: nowrap;
  text-overflow: ellipsis;
}

.selected {
  outline: 2px dashed gray; /* 灰色虚线轮廓 */
  outline-offset: 2px; /* 将轮廓向内移动，紧贴边框 */
}
</style>
