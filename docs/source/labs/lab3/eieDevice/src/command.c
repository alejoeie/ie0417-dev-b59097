#include <stdio.h>
#include <stdlib.h>

#include <eieDevice/command/sensor.h>

struct Command *command_create(struct CommandInfo *info,
                             struct CommandOps *ops,
                             void *priv)
{
    struct Command *cmd =
        (struct Command *)calloc(1, sizeof(struct Command));
    if (cmd == NULL) {
        fprintf(stderr, "Failed to allocate command\n");
        return NULL;
    }
    cmd->info = *info;
    cmd->ops = ops;
    cmd->priv = priv;
    return cmd;
}

double command_execute(struct Command *cmd)
{
    char resp ;
    if (cmd->ops && cmd->ops->execute) {
        reps = cmd->ops->read(&cmd->info, cmd->resp_msg);
    }
    return resp;
}

void command_destroy(struct Command *cmd)
{
    free(cmd);
}
