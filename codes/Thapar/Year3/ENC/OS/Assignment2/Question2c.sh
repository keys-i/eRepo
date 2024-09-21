#!/bin/bash
# `if-elif-else`
if [ "$NAME" == "John" ]; then
    echo "Welcome, John!"
elif [ "$NAME" == "Jane" ]; then
    echo "Welcome, Jane!"
else
    echo "Who are you?"
fi

# `case`
#!/bin/bash

case "$1" in
  "start")
    echo "Starting the process..."
    ;;
  "stop")
    echo "Stopping the process..."
    ;;
  "restart")
    echo "Restarting the process..."
    ;;
  *)
    echo "Unknown command: $1"
    ;;
esac
