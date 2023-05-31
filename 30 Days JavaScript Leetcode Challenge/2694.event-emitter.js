class EventEmitter {
    constructor() {
        this.events  = new Map();
    }
    subscribe(event, cb) {
        if(!this.events.has(event)) {
            this.events.set(event, []);
        }
        const subs = this.events.get(event);
        subs.push(cb);
      return {
          unsubscribe: () => {
            const index = subs.indexOf(cb);
            if(index!==-1){
                subs.splice(index, 1);
            }
          }
      };
    }
  
    emit(event, args = []) {
        if(!this.events.has(event)) {
            return [];
        }
        const subs = this.events.get(event);
        return subs.map(cb => cb(...args));
    }
  }
  
  /**
   * const emitter = new EventEmitter();
   *
   * // Subscribe to the onClick event with onClickCallback
   * function onClickCallback() { return 99 }
   * const sub = emitter.subscribe('onClick', onClickCallback);
   *
   * emitter.emit('onClick'); // [99]
   * sub.unsubscribe(); // undefined
   * emitter.emit('onClick'); // []
   */